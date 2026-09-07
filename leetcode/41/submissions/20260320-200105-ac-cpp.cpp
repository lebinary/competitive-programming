/*
 * 41. First Missing Positive
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 55.1 MB (beats 31.2%)
 * Submitted: 2026-03-20 20:01:06 UTC
 * URL: https://leetcode.com/submissions/detail/1954266055/
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 0;
        }

        for(int i = 0; i < n; ++i) {
            while(nums[i] != 0 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            };
        }

        int res = n + 1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                res = i + 1;
                break;
            }  
        }
        return res;
    }
};

/**
Approach:
- Mark any number that is <= 0 or > n as "irrelavant"
    - Let x be the missing number, if all n number in nums <= n, then x > n because there is no space for x to squeeze in
- Scan the array again, swap(nums[i], nums[nums[i]])
- Scan last time, pick the first index that is 0
**/
