# 19. Remove Nth Node From End of List
# Difficulty: Medium
# Status: Accepted
# Runtime: 28 ms (beats 0.4%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-10 12:54:51 UTC
# URL: https://leetcode.com/submissions/detail/1385370160/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # insight: consider n as size of window, 
        # move window to the end, then left is the node that needs removing
        dummy = ListNode(0, head)
        left = dummy

        # find "right"
        while n > 0:
            head = head.next
            n -= 1
        right = head

        # slide window to the end
        while right:
            left = left.next
            right = right.next

        # remove node at left.next (why left.next? because left starts at dummy)
        left.next = left.next.next

        return dummy.next
