# 653. Two Sum IV - Input is a BST
# Difficulty: Easy
# Status: Accepted
# Runtime: 11 ms (beats 19.5%)
# Memory: 21.8 MB (beats 92.5%)
# Submitted: 2026-05-05 18:01:13 UTC
# URL: https://leetcode.com/submissions/detail/1996056494/

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
        if not self.stack:
            return None
        top = self.stack.pop()
        
        node = top.right
        while node:
            self.stack.append(node)
            node = node.left
    
    def value(self):
        return self.stack[-1].val if self.stack else None

class BSTIteratorReverse:
    def __init__(self, root):
        self.root = root
        self.stack = []
        node = root
        while node:
            self.stack.append(node)
            node = node.right
    
    def next(self):
        if not self.stack:
            return None
        top = self.stack.pop()
        
        node = top.left
        
        while node:
            self.stack.append(node)
            node = node.right
    
    def value(self):
        return self.stack[-1].val if self.stack else None

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        leftIterator = BSTIterator(root)
        rightIterator = BSTIteratorReverse(root)
        
        while leftIterator.stack and rightIterator.stack and leftIterator.value() < rightIterator.value():
            total = leftIterator.value() + rightIterator.value()
            if total == k:
                return True
            elif total < k:
                leftIterator.next()
            else:
                rightIterator.next()
        
        return False
