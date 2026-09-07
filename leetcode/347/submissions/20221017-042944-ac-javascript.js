/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 87 ms (beats 5.3%)
 * Memory: 44 MB (beats 100.0%)
 * Submitted: 2022-10-17 04:29:44 UTC
 * URL: https://leetcode.com/submissions/detail/824175254/
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    let map = new Map();
    for(let i = 0; i < nums.length; i++){
        if(map.has(nums[i])){
            map.set(nums[i], map.get(nums[i]) + 1);
        }else{
            map.set(nums[i], 1);
        }
    }
    
    let list = [...map];
    list.sort((o1, o2) => o2[1] - o1[1]);
    
    let res = new Array(k);
    for(let i = 0; i < k; i++){
        res[i] = list[i][0];
    }
    
    return res;
};
