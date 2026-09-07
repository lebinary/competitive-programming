/*
 * 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14 MB (beats 94.7%)
 * Submitted: 2026-01-18 08:46:09 UTC
 * URL: https://leetcode.com/submissions/detail/1888705589/
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
                int i = 0;
                while (i < sub.size() && sub[i] < num) i++;
                sub[i] = num;
            }
        }

        return sub.size();
    }
};
