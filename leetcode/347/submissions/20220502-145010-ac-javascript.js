/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 70 ms (beats 5.3%)
 * Memory: 44.3 MB (beats 100.0%)
 * Submitted: 2022-05-02 14:50:10 UTC
 * URL: https://leetcode.com/submissions/detail/691651400/
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    let map = new Map();
    for(let num of nums){
        let count = map.get(num);
        
        if(!count){
            map.set(num, 1);
        }else{
            map.set(num, count+1);
        }
    }

    let list = [...map];
    list.sort((o1, o2) => {
        return o2[1] - o1[1];
    });
    
    let res = new Array(k);
    for (let i = 0; i < k; i++){
        res[i] = list[i][0];
    }
    return res;
};
