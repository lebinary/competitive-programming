# 206. Reverse Linked List
# Difficulty: Easy
# Status: Accepted
# Runtime: 37 ms (beats 0.5%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2024-09-10 10:30:19 UTC
# URL: https://leetcode.com/submissions/detail/1385258573/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head

        while curr:
            temp = curr.next
            curr.next = prev

            prev = curr
            curr = temp
        
        return prev
