/*
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 2 ms (beats 30.6%)
 * Memory: 97.5 MB (beats 25.8%)
 * Submitted: 2026-03-10 12:23:59 UTC
 * URL: https://leetcode.com/submissions/detail/1943899920/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        int l = 0;
        for(int r = 0; r < n; ++r) {
            while(prices[l] > prices[r]) l++;
            res = max(res, prices[r] - prices[l]);
        }
        return res;
    }
};



/***
[7,5,1,5,7] => 6
[5,6,7,3,1] => 2

[-2,-1,0,6,3,5] => 5

Approach: Two pointers
- [l, r+1] when l <= r
- [l+1, r] when l > r 
***/
