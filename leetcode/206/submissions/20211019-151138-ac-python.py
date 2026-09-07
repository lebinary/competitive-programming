# 206. Reverse Linked List
# Difficulty: Easy
# Status: Accepted
# Runtime: 35 ms (beats 1.6%)
# Memory: 15.4 MB (beats 7.3%)
# Submitted: 2021-10-19 15:11:38 UTC
# URL: https://leetcode.com/submissions/detail/573800552/

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
        cur = head
        prev = None
        
        while cur != None:
            temp_next = cur.next
            cur.next = prev
            prev = cur
            cur = temp_next
            
        return prev
            
        
        
        
