# 235. Lowest Common Ancestor of a Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 69 ms (beats 5.0%)
# Memory: 20.4 MB (beats 47.3%)
# Submitted: 2026-05-04 14:30:02 UTC
# URL: https://leetcode.com/submissions/detail/1995018659/

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

        def postorder(node):
            if not node:
                return False
            
            curr, left, right = False, False, False

            if p.val < node.val and q.val < node.val:
                left = postorder(node.left)
            elif p.val > node.val and q.val > node.val:
                right = postorder(node.right)
            else:
                curr = node == p or node == q
                left = postorder(node.left)
                right = postorder(node.right)

            if curr + left + right >= 2:
                res[0] = node 

            return curr or left or right

        postorder(root)
        return res[0]
