# 2. Add Two Numbers
# Difficulty: Medium
# Status: Accepted
# Runtime: 54 ms (beats 6.5%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-19 16:08:30 UTC
# URL: https://leetcode.com/submissions/detail/1395592767/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, None)
        node = dummy
        
        extra = 0
        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            curr_sum = extra + val1 + val2
            val = curr_sum % 10
            extra = curr_sum // 10

            node.next = ListNode(val, None)
            node = node.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        if extra > 0:
            node.next = ListNode(extra, None)
        
        return dummy.next
