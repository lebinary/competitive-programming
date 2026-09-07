/*
 * 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 127 ms (beats 3.5%)
 * Memory: 42.5 MB (beats 100.0%)
 * Submitted: 2022-09-27 14:42:18 UTC
 * URL: https://leetcode.com/submissions/detail/809847281/
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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {    
    let dummy = new ListNode(0, head);
    let left = dummy;
    let right = head;
    
    while(n > 0 && right){
        right = right.next;
        n -= 1;
    }
    
    while(right){
        left = left.next;
        right = right.next;
    }
    
    // remove node
    left.next = left.next.next;
    
    return dummy.next;
};
