/*
 * 2. Add Two Numbers
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 169 ms (beats 5.0%)
 * Memory: 47.4 MB (beats 100.0%)
 * Submitted: 2022-09-28 14:12:06 UTC
 * URL: https://leetcode.com/submissions/detail/810616238/
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let dummy = new ListNode(0, null);
    let curr = dummy;
    let carry = 0;
    
    while(l1 || l2 || carry !== 0){
        let l1Val = l1? l1.val : 0;
        let l2Val = l2? l2.val : 0;
        
        let colSum = l1Val + l2Val + carry;
        carry = Math.floor(colSum / 10);
        
        let newNode = new ListNode(colSum % 10, null);
        curr.next = newNode;
        curr = newNode;
        
        l1 = l1? l1.next : null;
        l2 = l2? l2.next : null;
    }
    
    return dummy.next;
};
