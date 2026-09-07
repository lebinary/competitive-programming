# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 54 ms (beats 96.1%)
# Memory: 20.3 MB (beats 100.0%)
# Submitted: 2024-09-01 12:03:18 UTC
# URL: https://leetcode.com/submissions/detail/1375339746/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        
        # case 1: either p or q equals root, returns root as lca 
        if root.val == p.val or root.val == q.val:
            return root
        
        # case 2: both p and q larger than root, look in right sub-tree, returns p-node | q-node | None
        p_or_q_right = self.lowestCommonAncestor(root.right, p, q)

        # case 3: both p and q smaller than root, look in left sub-tree, returns q-node | p-node | None
        p_or_q_left = self.lowestCommonAncestor(root.left, p, q)

        if p_or_q_left and p_or_q_right: # meaning there is a split
            return root
        elif p_or_q_left: # only p or q exists in the tree
            return p_or_q_left
        else:
            return p_or_q_right
