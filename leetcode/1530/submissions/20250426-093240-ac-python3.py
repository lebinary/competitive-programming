# 1530. Number of Good Leaf Nodes Pairs
# Difficulty: Medium
# Status: Accepted
# Runtime: 870 ms (beats 11.2%)
# Memory: 19.5 MB (beats 99.6%)
# Submitted: 2025-04-26 09:32:40 UTC
# URL: https://leetcode.com/submissions/detail/1618245332/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        leafs = []

        def build_graph(prev_node, node):
            if not node:
                return

            node.parent = prev_node
            if not node.left and not node.right:
                leafs.append(node)

            build_graph(node, node.left)
            build_graph(node, node.right)
        
        build_graph(None, root)

        def bfs(node):
            q = deque([node])
            visited = set()
            count = 0
            radius = 0

            while q:
                if radius > distance:
                    break

                for _ in range(len(q)):
                    curr = q.popleft()

                    if curr in visited:
                        continue
                    if curr in leafs and radius > 0:
                        count += 1
                    if curr.parent:
                        q.append(curr.parent)
                    if curr.left:
                        q.append(curr.left)
                    if curr.right:
                        q.append(curr.right) 
                    visited.add(curr)
                
                radius += 1
            return count

        res = 0
        for leaf in leafs:
            res += bfs(leaf)
        
        return res // 2



            
