# 700. Search in a Binary Search Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 20.9 MB (beats 41.3%)
# Submitted: 2026-04-14 13:51:45 UTC
# URL: https://leetcode.com/submissions/detail/1978314694/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return None
        
        if root.val == val:
            return root
        
        if val < root.val:
            return self.searchBST(root.left, val)

        return self.searchBST(root.right, val) 

        
