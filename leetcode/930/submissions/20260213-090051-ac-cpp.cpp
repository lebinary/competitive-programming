/*
 * 930. Binary Subarrays With Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 23 ms (beats 18.5%)
 * Memory: 40 MB (beats 8.9%)
 * Submitted: 2026-02-13 09:00:52 UTC
 * URL: https://leetcode.com/submissions/detail/1917826827/
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), count = 0, sum = 0;
        vector<int> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = 1;

        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i] += sum;

            if(map.count(prefix[i] - goal)) count += map[prefix[i] - goal];
            map[prefix[i]]++;
        }

        return count;
    }
};
