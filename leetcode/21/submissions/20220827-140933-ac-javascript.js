/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 113 ms (beats 3.3%)
 * Memory: 44.2 MB (beats 100.0%)
 * Submitted: 2022-08-27 14:09:33 UTC
 * URL: https://leetcode.com/submissions/detail/784730430/
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let dummy = new ListNode(0, null);
    let tail = dummy;
    
    while(list1 && list2){
        if(list1.val <= list2.val){
            tail.next = list1;
            list1 = list1.next;
        }else{
            tail.next = list2;
            list2 = list2.next;
        }
        
        tail = tail.next;
    }
    tail.next = list1 || list2
    
    return dummy.next;
};
