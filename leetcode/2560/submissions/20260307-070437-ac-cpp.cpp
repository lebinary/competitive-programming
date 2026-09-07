/*
 * 2560. House Robber IV
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 20 ms (beats 61.9%)
 * Memory: 60.8 MB (beats 69.6%)
 * Submitted: 2026-03-07 07:04:38 UTC
 * URL: https://leetcode.com/submissions/detail/1940539237/
 */

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = INT_MAX, r = INT_MIN;

        for(int num : nums) {
            l = min(l, num);
            r = max(r, num);
        }

        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(nums, n, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<int> &nums, int n, int k, int cand) {
        int count = 0, i = 0;

        while(i < n) {
            if(nums[i] <= cand) {
                count++;
                i += 2;
            } else i++;
        }

        return count >= k;
    }
};

/**
Approach 1: 
- BS on capability => candidate
- Validator: 
    Any value in nums s.t. nums[i] > cand is invalid
    [1,1,0,0,1,0,1] 1: robbable 0: cant robbed
    run dfs on [1,1,0,0,1,0,1] => number of houses
    
    dfs(nums, i):
        if i >= n: ret 0

        res = 0
        if nums[i] <= cand: 
            res = max(res, 1 + dfs(nums, i + 2))
            res = max(res, dfs(nums, i + 1))
        else:
            res = max(res, dfs(nums, i + 1))
        
        return res
=> Approach 1 gets TLE

Approach 2: BS + greedy validator
- Greedy Algo:
    Proof why greedy works:
    [...1,0,......]
        *
        here
    greedily pick "here" wont hurt your chance of getting to the maximum, there are 2 cases:
    - skip nums[i]=1 && pick nums[i+1]=1 => count=1
    - pick nums[i]=1 && skip nums[i+1]=1 => count=1
    - skip nums[i]=0 && pick nums[i+1]=1 => count=1
    => Therefore, greedy pick never worse 
**/ 
