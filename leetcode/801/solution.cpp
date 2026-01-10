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
    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return dfs(dp, nums1, nums2, n, false, 0);
    }

    int dfs(vector<vector<int>> &dp, vector<int> &nums1, vector<int> &nums2, int n, bool swapped, int i) {
        if (i >= n) return 0;
        if (dp[i][swapped] != -1) return dp[i][swapped];

        int best = INT_MAX;
        if (i == 0 || (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])) {
            best = min(best, dfs(dp, nums1, nums2, n, false, i + 1));
        }

        if (i == 0 || (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])) {
            swap(nums1[i], nums2[i]);

            int res = dfs(dp, nums1, nums2, n, true, i + 1);
            if (res != INT_MAX) {
                best = min(best, 1 + res);
            }

            swap(nums1[i], nums2[i]);
        }

        return dp[i][swapped] = best;
    }
};
