# 106. Construct Binary Tree from Inorder and Postorder Traversal
# Difficulty: Medium
# Status: Accepted
# Runtime: 8 ms (beats 42.2%)
# Memory: 21.4 MB (beats 42.3%)
# Submitted: 2026-04-14 12:29:17 UTC
# URL: https://leetcode.com/submissions/detail/1978252061/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_idx = {val:i for i, val in enumerate(inorder)}
        
        def dfs(l, r, i):
            print(f"l:{l} , r:{r}, i:{i}")
            if i < 0 or l > r:
                return None, 0

            p = inorder_idx[postorder[i]]
            
            node = TreeNode(postorder[i])
            node.right, rightSize = dfs(p + 1, r, i - 1)
            node.left, leftSize = dfs(l, p - 1, i - rightSize - 1)

            return node, leftSize + rightSize + 1

        res, size = dfs(0, len(inorder) - 1, len(postorder) - 1)
        return res

"""
Approach:
- dfs(i, l, r)
    p = find postorder[i] in inorder
    node = Node(i)
    node.left = dfs(l, p)
    node.right = dfs(p + 1, r)
     
    return node

"""

