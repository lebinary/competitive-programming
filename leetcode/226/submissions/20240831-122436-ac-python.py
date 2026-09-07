# 226. Invert Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 16 ms (beats 0.2%)
# Memory: 11.7 MB (beats 100.0%)
# Submitted: 2024-08-31 12:24:36 UTC
# URL: https://leetcode.com/submissions/detail/1374134597/

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
        # DFS iterative implementation
        if not root:
            return None
        
        stack = [root]
        while stack:
            print([s.val for s in stack])
            node = stack.pop()

            if node.left and not node.right:
                node.right = node.left
                node.left = None
                stack.append(node.right)
            elif node.right and not node.left:
                node.left = node.right
                node.right = None
                stack.append(node.left)
            elif node.left and node.right:
                tmp = node.left
                node.left = node.right
                node.right = tmp
                stack.append(node.left)
                stack.append(node.right)
            
        return root
