# 199. Binary Tree Right Side View
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 12.2 MB (beats 100.0%)
# Submitted: 2026-05-05 18:11:53 UTC
# URL: https://leetcode.com/submissions/detail/1996066530/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        if not root:
            return []

        res = []
        q = deque([root])

        while q:
            res.append(q[-1].val)

            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        
        return res
