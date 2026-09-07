# 226. Invert Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 20 ms (beats 0.2%)
# Memory: 13.4 MB (beats 4.6%)
# Submitted: 2022-03-07 09:55:31 UTC
# URL: https://leetcode.com/submissions/detail/655095264/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return
        
        tmp = root.left
        root.left = root.right
        root.right = tmp
        
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        return root
            
        
        
        
        
        
