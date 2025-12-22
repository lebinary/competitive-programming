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

class Solution {
  public:
    int minDeletionSize(vector<string> &strs) {
        int m = strs.size(), n = strs[0].size();
        if (m == 1) return 0;

        vector<bool> sorted(m - 1, false);
        int minDel = 0;

        for (int c = 0; c < n; ++c) {
            bool del = false;
            for (int r = 0; r < m - 1; ++r) {
                if (!sorted[r] && strs[r][c] > strs[r + 1][c]) {
                    del = true;
                    break;
                }
            }

            if (del)
                minDel++;
            else {
                for (int r = 0; r < m - 1; ++r) {
                    sorted[r] = sorted[r] || strs[r][c] < strs[r + 1][c];
                }
            }
        }

        return minDel;
    }
};
