/*
 * 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14.1 MB (beats 87.1%)
 * Submitted: 2026-01-18 08:49:22 UTC
 * URL: https://leetcode.com/submissions/detail/1888707754/
 */

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> sub;

        for (int num : nums) {
            if (sub.empty() || num > sub.back()) {
                sub.push_back(num);
            } else {
                int i = bs(sub, num);
                sub[i] = num;
            }
        }

        return sub.size();
    }

    int bs(vector<int> &arr, int num) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;

            if (arr[m] >= num) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};
