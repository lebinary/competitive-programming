# 21. Merge Two Sorted Lists
# Difficulty: Easy
# Status: Accepted
# Runtime: 36 ms (beats 0.9%)
# Memory: 16.4 MB (beats 100.0%)
# Submitted: 2024-09-10 10:54:56 UTC
# URL: https://leetcode.com/submissions/detail/1385276848/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Iterattive solution
        dummy = curr = ListNode()

        while list1 and list2:
            if list1.val <= list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        
        curr.next = list1 or list2

        return dummy.next
