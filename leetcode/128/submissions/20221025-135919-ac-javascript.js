/*
 * 128. Longest Consecutive Sequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 793 ms (beats 5.0%)
 * Memory: 58 MB (beats 100.0%)
 * Submitted: 2022-10-25 13:59:19 UTC
 * URL: https://leetcode.com/submissions/detail/829978524/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if(nums.length === 0) return 0;
    
    let set = new Set();
    for(let num of nums){
        set.add(num);
    }
    
    let longest = 1;
    
    for(let num of nums){
        if(set.has(num - 1)) continue;
        
        let curr_num = num;
        let curr_longest = 1;
        while(set.has(curr_num + 1)){
            curr_num++;
            curr_longest++;
        }
        
        longest = Math.max(curr_longest, longest);
    }
    
    return longest;
};
