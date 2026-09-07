/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 125 ms (beats 5.6%)
 * Memory: 45.3 MB (beats 100.0%)
 * Submitted: 2022-10-02 06:04:03 UTC
 * URL: https://leetcode.com/submissions/detail/813293245/
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
        fast = fast.next.next || null;
        
        if(slow === fast) return true;
    }
    
    return false;
};
