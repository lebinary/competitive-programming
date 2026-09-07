# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 76 ms (beats 5.0%)
# Memory: 20.4 MB (beats 47.3%)
# Submitted: 2026-05-04 13:54:00 UTC
# URL: https://leetcode.com/submissions/detail/1994994179/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        res = [None] 

        def preorder(node):
            if not node:
                return False
            
            curr = node == p or node == q
            left = preorder(node.left)
            right = preorder(node.right)

            if curr + left + right >= 2:
                res[0] = node
            
            return curr or left or right
        
        preorder(root)
        return res[0] 
        
