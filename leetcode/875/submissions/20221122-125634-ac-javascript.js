/*
 * 875. Koko Eating Bananas
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 102 ms (beats 5.2%)
 * Memory: 45.1 MB (beats 100.0%)
 * Submitted: 2022-11-22 12:56:34 UTC
 * URL: https://leetcode.com/submissions/detail/848010743/
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
        let k = Math.floor((r + l) / 2);
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
