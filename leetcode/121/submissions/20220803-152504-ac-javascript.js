/*
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 120 ms (beats 6.8%)
 * Memory: 51.1 MB (beats 100.0%)
 * Submitted: 2022-08-03 15:25:04 UTC
 * URL: https://leetcode.com/submissions/detail/764243183/
 */

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let maxProfit = 0;
    let l = 0;
    let r = 1;
    
    while(r < prices.length){
        if(prices[r] > prices[l]){
            maxProfit = Math.max((prices[r]-prices[l]), maxProfit);
        }else{
            l = r;
        }
        r++;
    }
    
    return maxProfit;
};
