/*
 * 123. Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 12 ms (beats 76.9%)
 * Memory: 85.4 MB (beats 69.1%)
 * Submitted: 2026-03-23 13:29:51 UTC
 * URL: https://leetcode.com/submissions/detail/1956724730/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefix(n, 0), suffix(n, 0);

        int l = 0, profit = 0;
        for(int r = 0; r < n; ++r) {
            while(l <= r && prices[l] > prices[r]) l++;
            profit = max(profit, prices[r] - prices[l]);
            prefix[r] = profit;
        }

        profit = 0;
        int r = n - 1;
        for(int l = n - 1; l >= 0; --l) {
            while(l <= r && prices[l] > prices[r]) r--;
            profit = max(profit, prices[r] - prices[l]);
            suffix[l] = profit;
        }

        int res = suffix[0];
        for(int i = 0; i < n; ++i) {
            int leftMax = prefix[i], rightMax = i + 1 < n ? suffix[i + 1] : 0;
            res = max(res, leftMax + rightMax);
        }

        return res;
    }
};

/**
What state? How many?
- current day: n
- current position: 2 (hold, not hold)
=> O(d * 2) = 10^5 < 10^7

# Approach 2: divide and conquer
- Build prefix[i] - max profit from left side
- Build suffix[i] - max profit from right side
- For each i:
    res = max(res, prefix[i] + suffix[i+1])
**/
