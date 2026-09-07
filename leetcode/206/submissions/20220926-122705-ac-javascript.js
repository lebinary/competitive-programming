/*
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 80 ms (beats 1.0%)
 * Memory: 44.1 MB (beats 100.0%)
 * Submitted: 2022-09-26 12:27:05 UTC
 * URL: https://leetcode.com/submissions/detail/808981863/
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
 * @return {ListNode}
 */
var reverseList = function(head) {
    let prev = null;
    
    while(head){
        let next = head.next;
        head.next = prev;
        
        prev = head;
        head = next;
    }
    
    return prev;
};
