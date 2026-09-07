# 145. Binary Tree Postorder Traversal
# Difficulty: Easy
# Status: Accepted
# Runtime: 12 ms (beats 0.0%)
# Memory: 13.3 MB (beats 1.0%)
# Submitted: 2021-09-30 17:06:12 UTC
# URL: https://leetcode.com/submissions/detail/563566381/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []        
        
        def postOrder(node):
            if node is None:
                return None

            postOrder(node.left)
            postOrder(node.right)

            ans.append(node.val)
        
        if root is not None: postOrder(root)
        return ans
