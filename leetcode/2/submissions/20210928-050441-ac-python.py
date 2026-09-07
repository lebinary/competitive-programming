# 2. Add Two Numbers
# Difficulty: Medium
# Status: Accepted
# Runtime: 64 ms (beats 5.8%)
# Memory: 13.4 MB (beats 22.6%)
# Submitted: 2021-09-28 05:04:41 UTC
# URL: https://leetcode.com/submissions/detail/562213388/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        curr = ListNode(0)
        l3 = curr
        carry = 0
        while l1 is not None or l2 is not None:
            x = l1.val if l1 is not None else 0
            y = l2.val if l2 is not None else 0
            
            total = carry + x + y
            carry = total / 10
            
            curr.next = ListNode(total % 10)
            curr = curr.next
            # next iteration
            if l1 is not None: l1 = l1.next
            if l2 is not None: l2 = l2.next
        
        if carry > 0:
            curr.next = ListNode(carry)
            
            
        return l3.next
            
            
                
            
