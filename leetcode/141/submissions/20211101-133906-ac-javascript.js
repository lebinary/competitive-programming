/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 72 ms (beats 5.6%)
 * Memory: 41.1 MB (beats 100.0%)
 * Submitted: 2021-11-01 13:39:06 UTC
 * URL: https://leetcode.com/submissions/detail/580446821/
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

// HASH APPROACH
// var hasCycle = function(head) {
//     let set = new Set();
//     while(head !== null){
//         if(set.has(head)){
//             return true
//         }else{
//             set.add(head)
//         }
//         head = head.next;
//     }
//     return false;
// };

// CYCLE-FINDING ALGORITHMS: 
// use 2 pointers, slow_p move 1 node at a time, fast_p move 2 nodes at a time
// if these 2 pointers meet -> there is a loop

var hasCycle = function(head) {
    let slow_p = head;
    let fast_p = head;
    while(slow_p !== null && fast_p !== null && fast_p.next !== null){
        slow_p = slow_p.next;
        fast_p = fast_p.next.next;
        if(slow_p === fast_p){
            return true;
        }
    }
    return false;
};
