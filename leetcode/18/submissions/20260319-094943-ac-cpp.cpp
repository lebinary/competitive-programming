/*
 * 18. 4Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 16 ms (beats 87.4%)
 * Memory: 17.5 MB (beats 57.3%)
 * Submitted: 2026-03-19 09:49:44 UTC
 * URL: https://leetcode.com/submissions/detail/1952895324/
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int l = 0; l < n - 3; ++l) {
            if(l > 0 && nums[l] == nums[l-1]) continue;
            
            for(int r = n - 1; r >= l + 3; r--) {
                if(r < n - 1 && nums[r] == nums[r + 1]) continue;

                int ll = l + 1, rr = r - 1;
                while(ll < rr) {
                    long long tot = (long long)nums[l] + nums[ll] + nums[rr] + nums[r];
                    if(tot == target) {
                        res.push_back({nums[l], nums[ll], nums[rr], nums[r]});
                        ll++; rr--;

                        while(ll < rr && nums[ll] == nums[ll - 1]) ll++;
                        while(ll < rr && nums[rr] == nums[rr + 1]) rr--;
                    } else if(tot < target) ll++;
                    else rr--;
                }
            }
        }

        return res;
    }
};

/**
- Bruteforce: O(n^4) = 200^4 = 8 * 10^6
- Divide and Conquer: split into 2 partitions => WONT WORK, too many cases
- 4 pointers? l_outer, r_outer, l_inner, r_inner
    for each l_outer, find the rightmost r_outer s.t nums[l_outer] + nums[r_outer] < target
        l_inner = l_outer + 1
        r_inner = r_outer - 1
        // same trick as 3Sum
    TC: O(n^3) = 200^3 = 8 * 10^5
**/
