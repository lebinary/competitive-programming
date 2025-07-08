#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class UnionFind {
    int n;
    vector<int> Parent;
    vector<int> Size;

  public:
    UnionFind(int n) : n(n), Parent(n), Size(n, 1) {
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
    }

    int find(int x) {
        if (x != Parent[x]) {
            Parent[x] = find(Parent[x]);
        }
        return Parent[x];
    }

    void unionNodes(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (Size[px] < Size[py]) swap(px, py);
        Size[py] += Size[px];
        Parent[px] = py;
        n--;
    }

    bool hasOneSet() { return n == 1; }
};

class Solution {
  public:
    bool canTraverseAllPairs(vector<int> &nums) {
        int n = nums.size();
        UnionFind uf(n);
        unordered_map<int, int> factor_idx;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int f = 2;

            while (f * f <= num) {
                if (num % f == 0) { // is a prime factor
                    if (factor_idx.count(f))
                        uf.unionNodes(i, factor_idx[f]);
                    else
                        factor_idx[f] = i;
                    while (num % f == 0) num /= f; // exhaust the prime factor
                }
                f++;
            }

            // "lefover" num is definitely a prime factor
            if (num > 1) {
                if (factor_idx.count(num))
                    uf.unionNodes(i, factor_idx[num]);
                else
                    factor_idx[num] = i;
            }
        }

        return uf.hasOneSet();
    };
};
