/*
 * 2706. Buy Two Chocolates
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 52.1 MB (beats 63.7%)
 * Submitted: 2026-08-06 15:47:13 UTC
 * URL: https://leetcode.com/submissions/detail/2096902125/
 */

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX, second = INT_MAX;

        for(int i = 0; i < prices.size(); ++i) {
            if(prices[i] < first) {
                second = min(second, first);
                first = prices[i];
            } else if(prices[i] < second){
                second = prices[i];
            }
        }
        
        int leftover = money - (first + second);
        return leftover >= 0 ? leftover : money;
    }
};
