/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 132 ms (beats 3.3%)
 * Memory: 44.2 MB (beats 100.0%)
 * Submitted: 2021-11-01 13:14:23 UTC
 * URL: https://leetcode.com/submissions/detail/580438627/
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
var mergeTwoLists = function(l1, l2) {
    let dummyNode = new ListNode(0);
    let tail = dummyNode;
    while(true){
        console.log();
        //If one list is done, attached the rest of the other
        if(l1 === undefined || l1 === null){
            tail.next = l2;
            break;
        }
        if(l2 === undefined || l2 === null){
            tail.next = l1;
            break;
        }
        
        //Comparing each node from 2 lists
        if(l1.val <= l2.val){
            tail.next = l1;
            l1 = l1.next;
            tail = tail.next;
        }else{
            tail.next = l2;
            l2 = l2.next;
            tail = tail.next;
        }
    }
    
    return dummyNode.next;
};
