/*
 * 1838. Frequency of the Most Frequent Element
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 39 ms (beats 60.2%)
 * Memory: 105.7 MB (beats 93.5%)
 * Submitted: 2026-04-03 14:48:42 UTC
 * URL: https://leetcode.com/submissions/detail/1967803498/
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;

        sort(nums.begin(), nums.end());

        int l = 0;
        long long cost = 0;
        for(int r = 0; r < n; ++r) {
            if(r > 0) cost += ((long long)nums[r] - nums[r - 1]) * (r - l); 

            while(l <= r && cost > k) {
                cost -= (nums[r] - nums[l]);
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};

/**
# Idea; Sliding window
- nums[r + 1] & nums[l]: "cost" increase => reaching k
- nums[l + 1] & nums[r]: "cost" decrease => decrease "cost" until <= k 

# Approach 2: Sort + Sliding window
- Sort nums non-dec
- Expand: cost += (nums[r] - nums[r - 1]) * (r - l)
- Shrink: cost -= (nums[r] - nums[l])  

TC: O(nlogn)
SC: O(alpha)
**/
