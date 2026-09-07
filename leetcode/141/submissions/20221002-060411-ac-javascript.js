/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 102 ms (beats 5.6%)
 * Memory: 45.8 MB (beats 100.0%)
 * Submitted: 2022-10-02 06:04:11 UTC
 * URL: https://leetcode.com/submissions/detail/813293316/
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let slow = head;
    let fast = head;
    
    while(slow && fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;
        
        if(slow === fast) return true;
    }
    
    return false;
};
