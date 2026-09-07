/*
 * 1248. Count Number of Nice Subarrays
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 88 ms (beats 7.9%)
 * Memory: 97.8 MB (beats 6.4%)
 * Submitted: 2026-02-13 09:07:11 UTC
 * URL: https://leetcode.com/submissions/detail/1917832153/
 */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, odds = 0;
        vector<int> prefix(n, 0);
        unordered_map<int, int> map;
        map[0] = 1;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] % 2 != 0) odds ++;
            prefix[i] = odds;

            if(map.count(prefix[i] - k)) count += map[prefix[i] - k];
            map[prefix[i]]++; 
        }

        return count; 
    }
};
