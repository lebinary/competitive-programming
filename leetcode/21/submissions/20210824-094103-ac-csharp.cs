/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 92 ms (beats 2.6%)
 * Memory: 26.4 MB (beats 100.0%)
 * Submitted: 2021-08-24 09:41:03 UTC
 * URL: https://leetcode.com/submissions/detail/543369390/
 */

// public class ListNode {
//   public int val;
//   public ListNode next;
//   public ListNode(int val=0, ListNode next=null) {
//       this.val = val;
//       this.next = next;
//   }
// }

public class Solution {    
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyNode = new ListNode(0);
        
        ListNode tail = dummyNode;
        
        while(true){
            if(l1 == null){
                tail.next = l2;
                break;
            }
            if(l2 == null){
                tail.next = l1;
                break;
            }
            
            if(l1.val <= l2.val){
                tail.next = l1;
                l1 = l1.next;
            }
            else{
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        
        return dummyNode.next;
    }
}
