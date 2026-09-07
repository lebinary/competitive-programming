# 143. Reorder List
# Difficulty: Medium
# Status: Accepted
# Runtime: 56 ms (beats 7.4%)
# Memory: 24.7 MB (beats 99.9%)
# Submitted: 2024-09-10 12:13:37 UTC
# URL: https://leetcode.com/submissions/detail/1385337011/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # find mid point
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # reverse second half
        prev, curr, follow = None, slow.next, None
        while curr:
            follow = curr.next
            curr.next = prev
            prev = curr
            curr = follow
        

        # merge 2 halves
        slow.next = None # break the link between first and second halves
        first, second = head, prev
        while second:
            follow1, follow2 = first.next, second.next

            first.next = second
            second.next = follow1

            first, second = follow1, follow2
