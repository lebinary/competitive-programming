/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 76 ms (beats 5.6%)
 * Memory: 42.2 MB (beats 100.0%)
 * Submitted: 2021-11-01 13:33:33 UTC
 * URL: https://leetcode.com/submissions/detail/580444973/
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
    let set = new Set();
    while(head !== null){
        if(set.has(head)){
            return true
        }else{
            set.add(head)
        }
        head = head.next;
    }
    return false;
};
