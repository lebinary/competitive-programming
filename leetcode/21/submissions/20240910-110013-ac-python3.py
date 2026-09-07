# 21. Merge Two Sorted Lists
# Difficulty: Easy
# Status: Accepted
# Runtime: 45 ms (beats 0.9%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-10 11:00:13 UTC
# URL: https://leetcode.com/submissions/detail/1385280914/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Recursive solution

        # base case: either list1 or list2 is None
        if not list1:
            return list2
        if not list2:
            return list1

        # check which is smaller
        small, big = (list1, list2) if list1.val <= list2.val else (list2, list1) 

        # recursive on the smaller.next
        small.next = self.mergeTwoLists(small.next, big)

        # return the smaller node
        return small
