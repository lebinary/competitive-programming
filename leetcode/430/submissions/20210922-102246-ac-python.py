# 430. Flatten a Multilevel Doubly Linked List
# Difficulty: Medium
# Status: Accepted
# Runtime: 28 ms (beats 41.9%)
# Memory: 14 MB (beats 6.0%)
# Submitted: 2021-09-22 10:22:46 UTC
# URL: https://leetcode.com/submissions/detail/559121728/

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head: return None
        
        stack = []
        curr = head
        
        while stack or curr:
            
            if curr.child:
                
                #save next node to has-child node in stack
                if curr.next:
                    stack.append(curr.next)
                 
                #flatten child to current node
                curr.next = curr.child
                curr.next.prev = curr
                curr.child = None
                
            elif stack and not curr.next:
                
                # pull out saved node from stack and attach to the tail
                node = stack.pop()
                curr.next = node
                node.prev = curr
                
            curr = curr.next
        
        return head

                
                
