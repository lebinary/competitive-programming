# 104. Maximum Depth of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 31 ms (beats 6.0%)
# Memory: 16 MB (beats 100.0%)
# Submitted: 2022-03-05 03:33:08 UTC
# URL: https://leetcode.com/submissions/detail/653547997/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    # Recusrsive DFS
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None: return 0
        
        left_count = 1 + self.maxDepth(root.left)
        
        right_count = 1 + self.maxDepth(root.right)
        
        return max(left_count, right_count)
    
    # Iterative BFS
#     def maxDepth(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         if root is None: return 0
        
#         level = 0
#         q = deque([root])
        
#         while q:
#             for i in range(len(q)):
#                 node = q.popleft()
#                 if node.left:
#                     q.append(node.left)
#                 if node.right:
#                     q.append(node.right)
#             level += 1
#         return level

    # Iterative DFS
#     def maxDepth(self, root):
#         """
#         :type root: TreeNode
#         :rtype: int
#         """
#         if root is None: return 0
        
#         level = 1
#         stack = [(root, level)]
        
#         while stack:
#             node, depth = stack.pop()
            
#             if node.left: 
#                 stack.append((node.left, depth+1))
            
#             if node.right:
#                 stack.append((node.right, depth+1))
            
#             level = max(level, depth)
        
#         return level
