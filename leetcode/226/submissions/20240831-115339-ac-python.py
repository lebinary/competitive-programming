# 226. Invert Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 4 ms (beats 1.9%)
# Memory: 11.5 MB (beats 100.0%)
# Submitted: 2024-08-31 11:53:39 UTC
# URL: https://leetcode.com/submissions/detail/1374113074/

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
        if root is None:
            return None

        tmp = root.left
        root.left = root.right
        root.right = tmp

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
        
