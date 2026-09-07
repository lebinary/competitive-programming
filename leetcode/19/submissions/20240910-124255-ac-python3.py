# 19. Remove Nth Node From End of List
# Difficulty: Medium
# Status: Accepted
# Runtime: 32 ms (beats 0.4%)
# Memory: 16.5 MB (beats 100.0%)
# Submitted: 2024-09-10 12:42:55 UTC
# URL: https://leetcode.com/submissions/detail/1385359880/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # reverse the list
        prev, curr, follow = None, head, None
        while curr:
          follow = curr.next
          curr.next = prev
          prev = curr
          curr = follow

        # traverse reversed list and remove the nth node
        count = 1
        reversed_head = prev
        prev, curr, follow = None, reversed_head, None
        while curr:
          follow = curr.next

          if count == n:
            if prev:
              prev.next = follow
            else:
              reversed_head = follow # beginning node
            break

          count += 1
          prev = curr
          curr = follow

        # reverse the list back
        prev, curr, follow = None, reversed_head, None
        while curr:
          follow = curr.next
          curr.next = prev
          prev = curr
          curr = follow
        
        return prev
