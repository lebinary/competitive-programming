# 872. Leaf-Similar Trees
# Difficulty: Easy
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2025-04-23 14:05:09 UTC
# URL: https://leetcode.com/submissions/detail/1615720216/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        st = []

        def dfs_append(node):
            if not node:
                return
            
            if not node.left and not node.right:
                st.append(node)
            
            dfs_append(node.left)
            dfs_append(node.right)

        dfs_append(root1)

        def dfs_check(node):
            if not node:
                return True
            
            if not node.left and not node.right:
                if len(st) == 0:
                    return False
                    
                leaf = st.pop()
                if node.val != leaf.val:
                    return False
            
            r = dfs_check(node.right)
            l = dfs_check(node.left)
            return r and l
        
        return dfs_check(root2) and len(st) == 0
        
