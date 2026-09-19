/*
 * 673. Number of Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 398 ms (beats 5.1%)
 * Memory: 288.9 MB (beats 5.1%)
 * Submitted: 2026-09-16 18:32:47 UTC
 * URL: https://leetcode.com/submissions/detail/2144019331/
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        int n = nums.size();
        vector<vector<int>> lenDP(n + 1, vector<int>(n + 1, -1));     
        vector<vector<int>> countDP(n + 1, vector<int>(n + 1, -1));   
        
        auto [maxLen, maxCount] = dfs(nums, lenDP, countDP, -1, 0);   
        
        return maxCount;
    }

    pair<int, int> dfs(vector<int>& nums, auto& lenDP, auto& countDP, int j, int i) {
        if(i >= nums.size()) return {0, 1};
        if(lenDP[i+1][j+1] != -1 && countDP[i+1][j+1] != -1) return { lenDP[i+1][j+1], countDP[i+1][j+1] };
        
        // take
        int lenA = 0, countA = 0;
        if(j == -1 || nums[i] > nums[j]) {
            auto [len, count] = dfs(nums, lenDP, countDP, i, i + 1);
            lenA = len + 1; countA = count;
        }

        // skip
        auto [lenB, countB] = dfs(nums, lenDP, countDP, j, i + 1);

        // determine res 
        pair<int, int> res;
        if(lenA == lenB) res = {lenA, countA + countB};
        else if(lenA > lenB) res = {lenA, countA};
        else res = {lenB, countB};

        // memoize & return
        lenDP[i+1][j+1] = res.first;
        countDP[i+1][j+1] = res.second;
        return res; 
    };
};

/**
Approach 1: DP on each starting position O(2^n)

res = {}
arr = []

dfs(i):
    if i >= n:
        res[arr.size] += 1
        return

    if arr.empty() || nums[i] > arr[-1]:
        arr << nums[i]
        dfs(i + 1)
    else:
        dfs(i + 1)

        while arr and arr[-1] >= nums[i]:
            arr.pop
        arr << nums[i]
        dfs(i + 1)

**/
