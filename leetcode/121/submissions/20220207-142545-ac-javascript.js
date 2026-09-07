/*
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3513 ms (beats 6.8%)
 * Memory: 87.2 MB (beats 5.1%)
 * Submitted: 2022-02-07 14:25:45 UTC
 * URL: https://leetcode.com/submissions/detail/636461268/
 */

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profit = 0;
    let l = 0;
    let r = 1;
    
    while(r < prices.length){
        console.log(l + ' ' + r);
        if(prices[l] < prices[r]){
            profit = Math.max(profit, prices[r] - prices[l])
        }else{
            l = r;
        }
        r++;
    }
    
    return profit;
};
