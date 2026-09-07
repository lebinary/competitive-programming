/*
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 121 ms (beats 1.0%)
 * Memory: 44 MB (beats 100.0%)
 * Submitted: 2022-12-07 13:57:10 UTC
 * URL: https://leetcode.com/submissions/detail/856128267/
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
