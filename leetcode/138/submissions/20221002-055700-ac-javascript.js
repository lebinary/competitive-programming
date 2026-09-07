/*
 * 138. Copy List with Random Pointer
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 106 ms (beats 5.7%)
 * Memory: 43.9 MB (beats 100.0%)
 * Submitted: 2022-10-02 05:57:00 UTC
 * URL: https://leetcode.com/submissions/detail/813289261/
 */

/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
    const oldToCopy = new Map();
    
    let cur = head;
    while(cur){
        let copy = new ListNode(cur.val);
        oldToCopy.set(cur, copy);
        cur = cur.next;
    }
    
    cur = head;
    while(cur){
        let copy = oldToCopy.get(cur);
        copy.next = oldToCopy.get(cur.next) || null;
        copy.random = oldToCopy.get(cur.random);
        cur = cur.next;
    }
    
     return oldToCopy.get(head);
};
