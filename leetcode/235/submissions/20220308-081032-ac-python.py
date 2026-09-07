# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 81 ms (beats 5.0%)
# Memory: 21.4 MB (beats 10.6%)
# Submitted: 2022-03-08 08:10:32 UTC
# URL: https://leetcode.com/submissions/detail/655744054/

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
        cur = root
        
        while cur:
            if p.val > cur.val and q.val > cur.val:
                cur = cur.right
            elif p.val < cur.val and q.val < cur.val:
                cur = cur.left
            else:
                return cur
            
            
