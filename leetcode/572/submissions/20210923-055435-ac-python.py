# 572. Subtree of Another Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 296 ms (beats 5.1%)
# Memory: 14.5 MB (beats 9.6%)
# Submitted: 2021-09-23 05:54:35 UTC
# URL: https://leetcode.com/submissions/detail/559581521/

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
        if root is None or subRoot is None:
            return False
        
        # Find the root of subTree in Tree
        subTreeRoots = self.findNode(root, subRoot.val, [])
        
        if len(subTreeRoots) > 0:
            # Compare root in tree and subtree
            for subTreeRoot in subTreeRoots:
                self.compareTrees(subTreeRoot, subRoot)
                if self.compareTrees(subTreeRoot, subRoot):
                    return True
            return False
        return False
        
    def findNode(self, node, key, results):
        if node is None:
            return results
        
        if node.val == key:
            results.append(node)
        
        results = self.findNode(node.left, key, results)        
        results = self.findNode(node.right, key, results)
        return results
    
    def compareTrees(self, root1, root2):
        if root1 is None and root2 is None:
            return True
        if root1 is not None and root2 is not None:
            return (root1.val == root2.val) and self.compareTrees(root1.left, root2.left) and  self.compareTrees(root1.right, root2.right)
        return False
        
        
        
