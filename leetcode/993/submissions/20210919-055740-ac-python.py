# 993. Cousins in Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 20 ms (beats 1.7%)
# Memory: 13.5 MB (beats 2.2%)
# Submitted: 2021-09-19 05:57:40 UTC
# URL: https://leetcode.com/submissions/detail/557365511/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        def findDepthandParent(root, key, parent):
            k = -1
            
            if root == None:
                return parent, k
            
            if root.val == key:
                return parent, k+1
            
            parent, k = findDepthandParent(root.left, key, root.val)
            if k >= 0:
                return parent, k+1
            
            parent, k = findDepthandParent(root.right, key, root.val)
            if k >= 0:
                return parent, k+1
            
            return parent, k
        
        #check if x and y have same depth and find their parents
        xParent, xDepth = findDepthandParent(root, x, -1)
        yParent, yDepth = findDepthandParent(root, y, -1)         
        
        #compare xParent and yParent
        if xParent > -1 and yParent > -1:
            if xParent != yParent and xDepth == yDepth:
                return True
        return False
