# 98. Validate Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 25 ms (beats 8.9%)
# Memory: 16.3 MB (beats 100.0%)
# Submitted: 2024-09-01 05:43:05 UTC
# URL: https://leetcode.com/submissions/detail/1375019317/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        stack = [(root, float('-inf'), float('inf'))]

        # DFS preorder
        while stack:
            node, min_val, max_val  = stack.pop()
            
            if node.val >= max_val or node.val <= min_val:
                return False

            if node.left:
                stack.append((node.left, min_val, node.val))
            
            if node.right:
                stack.append((node.right, node.val, max_val))
        
        return True
