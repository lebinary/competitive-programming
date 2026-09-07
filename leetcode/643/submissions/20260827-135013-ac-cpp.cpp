/*
 * 643. Maximum Average Subarray I
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 1 ms (beats 45.7%)
 * Memory: 113.9 MB (beats 27.8%)
 * Submitted: 2026-08-27 13:50:13 UTC
 * URL: https://leetcode.com/submissions/detail/2121952920/
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, largest = -INFINITY;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            if(i >= k) sum -= nums[i - k];
            
            if(i >= k - 1) largest = max(largest, sum);
        }

        return largest / k;
    }
};
