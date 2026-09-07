/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 92 ms (beats 5.6%)
 * Memory: 45 MB (beats 100.0%)
 * Submitted: 2022-08-27 15:15:04 UTC
 * URL: https://leetcode.com/submissions/detail/784769483/
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
    let slow = head, fast = head;
    
    while(slow !== null && fast !== null && fast.next !== null){
        slow = slow.next;
        fast = fast.next.next;
        
        if(slow === fast){
            return true;
        }
    }
    
    return false;
};
