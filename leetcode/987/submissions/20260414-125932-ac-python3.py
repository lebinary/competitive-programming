# 987. Vertical Order Traversal of a Binary Tree
# Difficulty: Hard
# Status: Accepted
# Runtime: 3 ms (beats 18.0%)
# Memory: 19.8 MB (beats 6.4%)
# Submitted: 2026-04-14 12:59:33 UTC
# URL: https://leetcode.com/submissions/detail/1978274268/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        labeled_nodes = []
        col_boundary = [float('inf'), float('-inf')]
        
        def dfs(node, r, c):
            if not node:
                return
            col_boundary[0] = min(col_boundary[0], c)
            col_boundary[1] = max(col_boundary[1], c)

            dfs(node.left, r + 1, c - 1)
            labeled_nodes.append((node.val, r, c))
            dfs(node.right, r + 1, c + 1)

        dfs(root, 0, 0)

        grouped_nodes = defaultdict(list)
        for val, row, col in labeled_nodes:
            grouped_nodes[col].append((row, val))
        
        for col in grouped_nodes.keys():
            grouped_nodes[col].sort(key=lambda x: (x[0], x[1]))

        min_col, max_col = col_boundary
        res = [[] for _ in range(max_col - min_col + 1)]

        for col, group in grouped_nodes.items():
            colIdx = col - min_col
            res[colIdx] = [val for row, val in group]
        
        return res
            
