#include <algorithm>
#include <cctype>
#include <climits>
#include <format>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class UF {
  public:
    vector<int> parents;
    int uniqCount;

    UF(int n) {
        this->parents = vector<int>(n);
        this->uniqCount = n;

        for (int i = 0; i < n; ++i) {
            this->parents[i] = i;
        }
    }

    int find(int i) {
        if (parents[i] == i) return i;
        return find(parents[i]);
    }

    void merge(int i, int j) {
        int ipar = find(i), jpar = find(j);
        if (ipar != jpar) uniqCount--;
        parents[ipar] = jpar;
    }
};

class Solution {
  public:
    int countComponents(int n, vector<vector<int>> &edges) {
        UF *uf = new UF(n);
        for (vector<int> edge : edges) {
            uf->merge(edge[0], edge[1]);
        }

        return uf->uniqCount;
    }
};
