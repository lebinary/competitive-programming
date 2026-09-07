# 236. Lowest Common Ancestor of a Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 48 ms (beats 100.0%)
# Memory: 27.9 MB (beats 100.0%)
# Submitted: 2026-04-24 18:06:20 UTC
# URL: https://leetcode.com/submissions/detail/1987214655/

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
        lca = [None]

        def postorder(node):
            if not node:
                return False
            
            left = postorder(node.left)
            right = postorder(node.right)
            mid = node == p or node == q

            # out of 3 nodes, if 2 are p or q, then the node is LCA
            if mid + left + right >= 2:
                lca[0] = node
            
            return mid or left or right
        
        postorder(root)
        return lca[0]
