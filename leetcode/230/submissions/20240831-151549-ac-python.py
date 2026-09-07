# 230. Kth Smallest Element in a BST
# Difficulty: Medium
# Status: Accepted
# Runtime: 28 ms (beats 5.0%)
# Memory: 19.3 MB (beats 100.0%)
# Submitted: 2024-08-31 15:15:49 UTC
# URL: https://leetcode.com/submissions/detail/1374325355/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        node = root

        while len(stack) >= 0:
            # go to most left
            while node:
                stack.append(node)
                node = node.left
            
            # pop latest node
            node = stack.pop()
            k -= 1
            
            if k == 0:
                return node.val

            node = node.right
