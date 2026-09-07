# 226. Invert Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 31 ms (beats 0.2%)
# Memory: 13.3 MB (beats 4.6%)
# Submitted: 2022-03-07 10:26:11 UTC
# URL: https://leetcode.com/submissions/detail/655105448/

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
        
        # Recursive DFS
#         if not root:
#             return
        
#         tmp = root.left
#         root.left = root.right
#         root.right = tmp
        
#         self.invertTree(root.left)
#         self.invertTree(root.right)
        
#         return root
    
        # Iterative BFS
        if not root: 
            return
        
        q = deque([root])
        
        while q:
            for i in range(len(q)):
                node = q.popleft()

                if node.left and not node.right:
                    node.right = node.left
                    node.left = None
                    q.append(node.right)
                
                elif node.right and not node.left:
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
        
        
        
        
        
