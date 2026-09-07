# 226. Invert Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 22 ms (beats 0.2%)
# Memory: 11.6 MB (beats 100.0%)
# Submitted: 2024-08-31 12:08:21 UTC
# URL: https://leetcode.com/submissions/detail/1374123339/

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
        # BFS implementation
        if root is None:
            return None
        
        q = deque([root])

        while q:
            for _ in range(len(q)):
                node = q.popleft()

                if node.left and not node.right:
                    node.right = node.left
                    node.left = None
                    q.append(node.right)
                elif not node.left and node.right:
                    node.left = node.right
                    node.right = None
                    q.append(node.left)
                elif node.left and node.right:
                    tmp = node.left
                    node.left = node.right
                    node.right = tmp
                    q.append(node.left)
                    q.append(node.right)
        
        return root
        
