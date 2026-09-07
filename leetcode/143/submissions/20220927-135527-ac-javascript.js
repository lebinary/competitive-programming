/*
 * 143. Reorder List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 169 ms (beats 5.1%)
 * Memory: 50.1 MB (beats 100.0%)
 * Submitted: 2022-09-27 13:55:27 UTC
 * URL: https://leetcode.com/submissions/detail/809817334/
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
     while(second){
         let next = second.next;
         second.next = prev;

         prev = second;
         second = next;
     }
    slow.next = null;
    
    // Merge first and second half
    let first = head;
    second = prev;
    while(second){
        let tmp1 = first.next;
        let tmp2 = second.next;
        
        first.next = second;
        second.next = tmp1;
        
        first = tmp1;
        second = tmp2;
    }
};
