/*
 * 143. Reorder List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 113 ms (beats 5.1%)
 * Memory: 50.5 MB (beats 100.0%)
 * Submitted: 2022-08-27 14:50:10 UTC
 * URL: https://leetcode.com/submissions/detail/784755061/
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    let slow = head; 
    let fast = head.next;
    
    while(fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;
    }
    
    let second = slow.next;
    
    // Reverse the second half
    let prev = null;
    slow.next = null;
    while(second){
        let tmp = second.next;
        second.next = prev;
        prev = second;
        second = tmp;
    }
    
    // Merge the first and second halves
    let first = head; 
    second = prev;
    while(second){
        let tmp1 = first.next, tmp2 = second.next;
        first.next = second;
        second.next = tmp1;
        
        first = tmp1;
        second = tmp2;
    }
};
