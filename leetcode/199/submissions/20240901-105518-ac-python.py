# 199. Binary Tree Right Side View
# Difficulty: Medium
# Status: Accepted
# Runtime: 19 ms (beats 1.7%)
# Memory: 11.6 MB (beats 100.0%)
# Submitted: 2024-09-01 10:55:18 UTC
# URL: https://leetcode.com/submissions/detail/1375283570/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # BFS
        if not root:
            return []

        q = deque([root])
        res = []

        while q:
            res.append(q[-1].val)

            for _ in range(len(q)):
                node = q.popleft()

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        
        return res
