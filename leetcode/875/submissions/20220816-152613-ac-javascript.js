/*
 * 875. Koko Eating Bananas
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 116 ms (beats 5.2%)
 * Memory: 45.6 MB (beats 100.0%)
 * Submitted: 2022-08-16 15:26:13 UTC
 * URL: https://leetcode.com/submissions/detail/775256599/
 */

/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let l = 1;
    let r = Math.max(...piles);
    let res = r;
    while(l <= r){
        let k = Math.floor((l+r)/2);
        
        let count = 0;
        for(let i = 0; i < piles.length; i++){
            count += Math.ceil(piles[i] / k);
        }
        
        if(count <= h){
            res = Math.min(res, k);
            r = k - 1;
        }else{
            l = k + 1;
        }
    }
    return res;
};
