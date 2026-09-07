/*
 * 2841. Maximum Sum of Almost Unique Subarray
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 58 ms (beats 71.2%)
 * Memory: 69 MB (beats 61.8%)
 * Submitted: 2026-02-16 03:25:17 UTC
 * URL: https://leetcode.com/submissions/detail/1920579875/
 */

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long res = 0, sum = 0;
        unordered_map<int, int> freq;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            sum += nums[r];
            freq[nums[r]]++;

            if(r >= k) {
                sum -= nums[l];
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }

            if(freq.size() >= m) {
                res = max(res, sum);
            }
        }

        return res;
    }
};
