# 206. Reverse Linked List
# Difficulty: Easy
# Status: Accepted
# Runtime: 55 ms (beats 1.6%)
# Memory: 18.7 MB (beats 5.1%)
# Submitted: 2021-10-19 15:25:31 UTC
# URL: https://leetcode.com/submissions/detail/573806667/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # Loop solution
#         cur = head
#         prev = None
        
#         while cur != None:
#             temp_next = cur.next
#             cur.next = prev
#             prev = cur
#             cur = temp_next
            
#         return prev
            
        # Recursive solution
        
        # base case
        if not head:
            return None
        
        newHead = head
        
        if head.next:
            newHead = self.reverseList(head.next)
            head.next.next = head
        head.next = None
        return newHead
        
        
