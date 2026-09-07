# 230. Kth Smallest Element in a BST
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 22.4 MB (beats 11.5%)
# Submitted: 2026-04-14 13:28:59 UTC
# URL: https://leetcode.com/submissions/detail/1978296720/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def __init__(self, root):
        self.stack = []
        
        node = root
        while node:
            self.stack.append(node)
            node = node.left

    def next(self):
        top = self.stack.pop()
        
        if top.right:
            node = top.right
            while node:
                self.stack.append(node)
                node = node.left

        return top.val

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return -1

        res = -1
        iterator = BSTIterator(root)
        for i in range(k):
            res = iterator.next()
            print(res)
        
        return res
