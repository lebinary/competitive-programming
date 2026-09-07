/*
 * 122. Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17 MB (beats 100.0%)
 * Submitted: 2025-06-12 12:09:04 UTC
 * URL: https://leetcode.com/submissions/detail/1661880884/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for(int i = 0; i < n -1; ++i) {
            if(prices[i + 1] > prices[i]) res += prices[i + 1] - prices[i];
        }
        return res;
    }
};
