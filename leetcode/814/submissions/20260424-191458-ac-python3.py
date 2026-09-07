# 814. Binary Tree Pruning
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 19.4 MB (beats 7.9%)
# Submitted: 2026-04-24 19:14:58 UTC
# URL: https://leetcode.com/submissions/detail/1987262137/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        delList = set()
        
        def postorder(node):
            if not node:
                return False
            
            left = postorder(node.left)
            right = postorder(node.right)

            if node.val == 0 and not left and not right:
                delList.add(node)

            return node.val == 1 or left or right

        postorder(root)

        def removeNode(node):
            if not node:
                return None
            
            node.left = removeNode(node.left)
            node.right = removeNode(node.right)

            if node in delList:
                delList.remove(node)
                return None
            else:
                return node
        
        return removeNode(root)
