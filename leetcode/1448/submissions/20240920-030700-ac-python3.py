# 1448. Count Good Nodes in Binary Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 126 ms (beats 68.7%)
# Memory: 31.6 MB (beats 99.5%)
# Submitted: 2024-09-20 03:07:00 UTC
# URL: https://leetcode.com/submissions/detail/1396042633/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = [0]
        def goodNode(root, curr_max):
            if not root:
                return
            
            if root.left:
                goodNode(root.left, max(curr_max, root.left.val))
            
            if root.right:
                goodNode(root.right, max(curr_max, root.right.val))
            
            if root.val >= curr_max:
                count[0] += 1
        
        goodNode(root, root.val)
        return count[0]
