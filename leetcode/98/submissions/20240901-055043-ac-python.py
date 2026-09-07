# 98. Validate Binary Search Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 34 ms (beats 8.9%)
# Memory: 16.1 MB (beats 100.0%)
# Submitted: 2024-09-01 05:50:43 UTC
# URL: https://leetcode.com/submissions/detail/1375025942/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # DFS recursive
        def dfs(node, min_val, max_val):
            if not node:
                return True

            if node.val >= max_val or node.val <= min_val:
                return False

            valid_l = dfs(node.left, min_val, node.val)
            valid_r = dfs(node.right, node.val, max_val)

            return valid_l and valid_r 
            
        return dfs(root, float('-inf'), float('inf'))
