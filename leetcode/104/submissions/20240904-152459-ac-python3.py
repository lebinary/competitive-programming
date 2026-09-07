# 104. Maximum Depth of Binary Tree
# Difficulty: Easy
# Status: Accepted
# Runtime: 38 ms (beats 9.0%)
# Memory: 17.5 MB (beats 100.0%)
# Submitted: 2024-09-04 15:24:59 UTC
# URL: https://leetcode.com/submissions/detail/1378933549/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0

        q = deque([root])
        depth = 0

        while q:
            depth += 1
            for _ in range(len(q)):
                curr = q.popleft()

                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
        return depth
