/*
 * 169. Majority Element
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 28.3 MB (beats 44.3%)
 * Submitted: 2026-03-21 13:27:10 UTC
 * URL: https://leetcode.com/submissions/detail/1954775600/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        srand(time(0));
        int n = nums.size();

        for(int k = 0; k < 10; ++k) {
            // check if the picked candidate is the result
            int candIdx = rand() % n;
            int count = 0;
            for(int i = 0; i < n; ++i) {
                if(nums[i] == nums[candIdx]) count++;
                if(count > n / 2) return nums[candIdx];
            }
        }
        return INT_MAX;
    }
};
/**
# Approach 2: 
Chance of pick the right candidate is p > 0.5, therefore chance of "never able to pick right candidate"
after k tries is: (1 - p)^k = 0.5^k. With k = 10, probability of "failing" is 0.0009 
**/
