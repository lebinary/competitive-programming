/*
 * 1695. Maximum Erasure Value
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 182 ms (beats 45.4%)
 * Memory: 131 MB (beats 29.3%)
 * Submitted: 2026-02-16 05:55:49 UTC
 * URL: https://leetcode.com/submissions/detail/1920697547/
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), best = 0, sum = 0;
        unordered_set<int> uniq;
        int l = 0;

        for(int r = 0; r < n; ++r) {
            while(l <= r && uniq.count(nums[r])) {
                sum -= nums[l];
                uniq.erase(nums[l++]);
            }

            sum += nums[r];
            uniq.insert(nums[r]);
            best = max(best, sum);
        }
        
        return best;
    }
};
