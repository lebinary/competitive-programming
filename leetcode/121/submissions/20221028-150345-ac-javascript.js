/*
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 148 ms (beats 6.8%)
 * Memory: 51.3 MB (beats 100.0%)
 * Submitted: 2022-10-28 15:03:45 UTC
 * URL: https://leetcode.com/submissions/detail/832118161/
 */

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let l = 0;
    let r = 1;
    let maxProfit = 0;
    
    while(l < prices.length && r < prices.length){
        let profit = prices[r] - prices[l];
        if(profit > 0) {
            maxProfit = Math.max(maxProfit, profit);
            r++;
        }else{
            l = r;
            r++;
        }
    }
    
    return maxProfit;
};
