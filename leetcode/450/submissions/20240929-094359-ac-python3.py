# 450. Delete Node in a BST
# Difficulty: Medium
# Status: Accepted
# Runtime: 57 ms (beats 2.2%)
# Memory: 19.9 MB (beats 100.0%)
# Submitted: 2024-09-29 09:43:59 UTC
# URL: https://leetcode.com/submissions/detail/1405945543/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return None

        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            
            # Find the max from left subtree, 
            # Copy its value to root,
            # Recursive delete it in left subtree  
            cur = root.left
            while cur.right:
                cur = cur.right
            root.val = cur.val
            root.left = self.deleteNode(root.left, root.val)

        return root

