# 572. Subtree of Another Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 164 ms (beats 5.1%)
# Memory: 14.6 MB (beats 9.6%)
# Submitted: 2022-03-08 07:47:39 UTC
# URL: https://leetcode.com/submissions/detail/655733429/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        if not subRoot: return True
        if not root: return False
        
        if self.isSameTree(root, subRoot):
            return True
        
        return (self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot))
        
    
    def isSameTree(self, p, q):
        if not p and not q: return True
        
        if p and q and p.val == q.val:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right) 
            
        return False
    
#         left_res = self.isSameTree(p.left, q.left)
#         right_res = self.isSameTree(p.left, q.left)
        
#         return left_res and right_res
        
