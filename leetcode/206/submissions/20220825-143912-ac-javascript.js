/*
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 102 ms (beats 1.0%)
 * Memory: 43.8 MB (beats 100.0%)
 * Submitted: 2022-08-25 14:39:12 UTC
 * URL: https://leetcode.com/submissions/detail/783128462/
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
