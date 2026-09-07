/*
 * 287. Find the Duplicate Number
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 111 ms (beats 8.1%)
 * Memory: 49.9 MB (beats 100.0%)
 * Submitted: 2022-10-04 15:46:50 UTC
 * URL: https://leetcode.com/submissions/detail/815090232/
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    // Linked list cycle problem, Find the intersection of slow and fast pointers
    let slow = 0;
    let fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow !== fast);
    
    
    /*** Use Floyd's algorithm, traverse from the head of linked list 
    and from the intersection at the same rate assuming they will meet at the start of a cycle
    ***/
    let slow2 = 0;
    do {
        slow = nums[slow];
        slow2 = nums[slow2];
    } while(slow !== slow2);
    
    return slow;
};

/*** Floyd's Algorithm

Description: The distance between the head of a linked list to the start of a cycle is always the same as the distance between the intersection of slow and fast pointers to the the start of a cycle.


***/
