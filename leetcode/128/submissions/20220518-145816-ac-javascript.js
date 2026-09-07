/*
 * 128. Longest Consecutive Sequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 758 ms (beats 5.0%)
 * Memory: 57.6 MB (beats 100.0%)
 * Submitted: 2022-05-18 14:58:16 UTC
 * URL: https://leetcode.com/submissions/detail/702144583/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if(nums.length === 0) return 0;
    
    const set = new Set();
    
    for(const num of nums) {
        set.add(num);
    }
    
    let longest_streak = 0;
    let cur_streak = 0;
    for(let i = 0; i < nums.length; i++) {
        cur_num = nums[i];
        
        // Only start counting if the number is the first in the sequence
        if(set.has(cur_num - 1)) continue;
        
        cur_streak = 0;
        while(set.has(cur_num)) {
            cur_streak++;
            cur_num++;
        }
        longest_streak = Math.max(cur_streak, longest_streak);
    }
    
    return longest_streak;
};
