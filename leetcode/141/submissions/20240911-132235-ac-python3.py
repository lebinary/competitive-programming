# 141. Linked List Cycle
# Difficulty: Easy
# Status: Accepted
# Runtime: 43 ms (beats 96.3%)
# Memory: 19.1 MB (beats 100.0%)
# Submitted: 2024-09-11 13:22:35 UTC
# URL: https://leetcode.com/submissions/detail/1386561970/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while slow and fast and slow.next and fast.next:
            slow = slow.next
            fast = fast.next.next if fast.next else None

            if slow == fast:
                return True
        
        return False
