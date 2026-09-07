# 24. Swap Nodes in Pairs
# Difficulty: Medium
# Status: Accepted
# Runtime: 31 ms (beats 0.5%)
# Memory: 16.4 MB (beats 100.0%)
# Submitted: 2024-09-24 10:20:02 UTC
# URL: https://leetcode.com/submissions/detail/1400578350/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None

        # if no pair, return head
        if not head.next:
            return head
        
        # if there is a pair, swap and return
        follow = head.next
        head.next = follow.next
        follow.next = head

        head.next = self.swapPairs(head.next)

        return follow
