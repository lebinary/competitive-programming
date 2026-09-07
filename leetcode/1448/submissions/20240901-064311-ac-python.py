# 1448. Count Good Nodes in Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 228 ms (beats 38.9%)
# Memory: 47.3 MB (beats 100.0%)
# Submitted: 2024-09-01 06:43:11 UTC
# URL: https://leetcode.com/submissions/detail/1375075636/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        
        stack = [(root, root.val)]
        count = 0

        while stack:
            node, max_val = stack.pop()

            if node.val >= max_val:
                count += 1

            if node.right:
                stack.append((node.right, max(node.right.val, max_val)))
            if node.left:
                stack.append((node.left, max(node.left.val, max_val)))
        
        return count

        
