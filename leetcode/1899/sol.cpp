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

class Solution {
  public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        int R = triplets.size(), C = triplets[0].size();
        unordered_set<int> ignoreRows;

        for (int c = 0; c < C; ++c) {
            for (int r = 0; r < R; ++r) {
                if (triplets[r][c] > target[c]) ignoreRows.insert(r);
            }
        }

        for (int c = 0; c < C; ++c) {
            int largest = INT_MIN;
            for (int r = 0; r < R; ++r) {
                if (ignoreRows.count(r)) continue;
                largest = max(largest, triplets[r][c]);
            }
            if (largest != target[c]) return false;
        }

        return true;
    }
};
