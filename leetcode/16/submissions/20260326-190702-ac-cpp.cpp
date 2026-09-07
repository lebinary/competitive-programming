/*
 * 16. 3Sum Closest
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 38.4%)
 * Memory: 13.9 MB (beats 99.4%)
 * Submitted: 2026-03-26 19:07:02 UTC
 * URL: https://leetcode.com/submissions/detail/1960285230/
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), diff = INT_MAX, res = 0;

        for(int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r]; 
                if(abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }

                if(sum == target) return sum;
                else if(sum > target) r--;
                else l++;
            }
        }

        return res;
    }
};

/**
# Approach 1: Sort + 2 pointers
- Sort first
- For each l:
    ll = l + 1, rr = n - 1
    
    while ll < rr:
        if |target - sum| < res: res = |target - sum|
        
        if sum >= target:
            sum -= nums[rr--]
            sum += nums[rr]
        else:
            sum -= nums[ll++]
            sum += nums[ll]
        
TC: O(n^2)
SC: O(alpha)
    


    
**/
