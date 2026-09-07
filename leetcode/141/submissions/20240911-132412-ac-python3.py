# 141. Linked List Cycle
# Difficulty: Easy
# Status: Accepted
# Runtime: 50 ms (beats 77.5%)
# Memory: 19.1 MB (beats 100.0%)
# Submitted: 2024-09-11 13:24:12 UTC
# URL: https://leetcode.com/submissions/detail/1386563559/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head: return False
        
        slow = head
        fast = head.next

        while slow and fast:
            if slow == fast:
                return True

            slow = slow.next
            fast = fast.next.next if fast.next else None

        return False
