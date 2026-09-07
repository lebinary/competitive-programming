/*
 * 410. Split Array Largest Sum
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 246 ms (beats 4.5%)
 * Memory: 12 MB (beats 5.3%)
 * Submitted: 2025-05-20 10:55:12 UTC
 * URL: https://leetcode.com/submissions/detail/1639213125/
 */

class Solution {
    int N;
    vector<int> nums;
    vector<vector<int>> dp;
public:
    int splitArray(vector<int>& nums, int k) {
        this->N = nums.size();
        this->nums = nums;
        dp.assign(N, vector<int>(k+1, -1));
        return dfs(0, k);
    }
private:
    int dfs(int i, int k) {
        if(i >= N) {
            return k == 0 ? 0 : INT_MAX;
        }
        if(k == 0) {
            return INT_MAX;
        }
        if(dp[i][k] != -1) return dp[i][k];
        
        int res = INT_MAX;
        int sum1 = 0;
        for (int j = i; j < N-k+1; ++j) {
            sum1 += nums[j];
            int sum2 = dfs(j+1, k-1);
            res = min(res, max(sum1, sum2));
        }

        return dp[i][k] = res;
    }
};
