# 572. Subtree of Another Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 80 ms (beats 5.2%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-05 11:51:14 UTC
# URL: https://leetcode.com/submissions/detail/1379876159/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        # Iterative check same tree for each node
        stack = [root]

        while stack:
            node = stack.pop()

            if self.isSameTree(node, subRoot):
                return True
            
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        
        return False


    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Iterative same tree approach
        stack = [(p, q)]

        while stack:
            curr_p, curr_q = stack.pop()

            if not curr_p and not curr_q:
                continue
            if (not curr_p and curr_q) or (not curr_q and curr_p):
                return False
            if curr_p.val != curr_q.val:
                return False
            
            stack.append((curr_p.left, curr_q.left))
            stack.append((curr_p.right, curr_q.right))
        
        return True
