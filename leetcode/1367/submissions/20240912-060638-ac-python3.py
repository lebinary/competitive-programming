# 1367. Linked List in Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 76 ms (beats 5.6%)
# Memory: 17.1 MB (beats 100.0%)
# Submitted: 2024-09-12 06:06:38 UTC
# URL: https://leetcode.com/submissions/detail/1387351137/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        stack = [root]

        while stack:
            curr = stack.pop()
            
            if self.isSame(head, curr):
                return True
            
            if curr.right:
                stack.append(curr.right)
            if curr.left:
                stack.append(curr.left)

        return False
            

    def isSame(self, listnode: Optional[ListNode], treenode: Optional[TreeNode]) -> bool:
        stack = [(listnode, treenode)]

        while stack:
            curr_listnode, curr_treenode = stack.pop()

            if not curr_listnode: # succesfully reach the end of linked list
                return True
            elif not curr_treenode:
                continue
            elif curr_listnode.val != curr_treenode.val:
                continue

            stack.append((curr_listnode.next, curr_treenode.right))
            stack.append((curr_listnode.next, curr_treenode.left))
        
        return False
