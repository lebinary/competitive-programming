# 1448. Count Good Nodes in Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 211 ms (beats 73.0%)
# Memory: 47.6 MB (beats 100.0%)
# Submitted: 2024-09-01 06:54:13 UTC
# URL: https://leetcode.com/submissions/detail/1375086071/

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
        
        def dfs(node, max_val):
            if not node:
                return 0
            
            count = 0
            if node.val >= max_val:
                count += 1
            
            new_max = max(max_val, node.val)

            count_l = dfs(node.left, new_max)
            count_r = dfs(node.right, new_max)

            return count + count_l + count_r
        
        return dfs(root, root.val)

        
