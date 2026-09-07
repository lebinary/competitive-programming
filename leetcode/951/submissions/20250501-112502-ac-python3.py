# 951. Flip Equivalent Binary Trees
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 18 MB (beats 100.0%)
# Submitted: 2025-05-01 11:25:02 UTC
# URL: https://leetcode.com/submissions/detail/1622731471/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    count1 = 0
    count2 = 0
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        if root1 and root2:
            count1, count2 = 0, 0
            count1 += 1 if root1.left else 0
            count1 += 1 if root1.right else 0
            count2 += 1 if root2.left else 0
            count2 += 1 if root2.right else 0

            if count1 != count2:
                return False

        if not root1 and not root2:
            return True
        if not root1 or not root2:
            return False

        leftEquiv = self.flipEquiv(root1.left, root2.right) or self.flipEquiv(root1.left, root2.left)
        rightEquiv = self.flipEquiv(root1.right, root2.left) or self.flipEquiv(root1.right, root2.right)

        return root1.val == root2.val and self.count1 == self.count2 and leftEquiv and rightEquiv
