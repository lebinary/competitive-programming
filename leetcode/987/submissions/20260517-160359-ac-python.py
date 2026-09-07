# 987. Vertical Order Traversal of a Binary Tree
# Difficulty: Hard
# Status: Accepted
# Runtime: 1 ms (beats 39.5%)
# Memory: 12.6 MB (beats 86.8%)
# Submitted: 2026-05-17 16:03:59 UTC
# URL: https://leetcode.com/submissions/detail/2005683753/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []

        res = []
        colMap = defaultdict(list) # {col -> (row, val)}
        q = deque([(root, 0, 0)]) # [(node, row, col)]
        minCol, maxCol = 0, 0

        while q:
            node, row, col = q.popleft()
            colMap[col].append((row, node.val))
            
            if node.left:
                q.append((node.left, row + 1, col - 1))
                minCol = min(minCol, col - 1)
            
            if node.right:
                q.append((node.right, row + 1, col + 1))
                maxCol = max(maxCol, col + 1)
        
        for col in range(minCol, maxCol + 1):
            res.append([val for _, val in sorted(colMap[col])])

        return res
