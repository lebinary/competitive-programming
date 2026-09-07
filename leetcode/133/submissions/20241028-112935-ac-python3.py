# 133. Clone Graph
# Difficulty: Medium
# Status: Accepted
# Runtime: 35 ms (beats 99.3%)
# Memory: 17 MB (beats 100.0%)
# Submitted: 2024-10-28 11:29:35 UTC
# URL: https://leetcode.com/submissions/detail/1436142471/

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        hm = {}
        def dfs(node):
            if node in hm:
                return hm[node]

            new_node = Node(node.val)
            # save to hashmap
            hm[node] = new_node

            # update neighbors
            new_node.neighbors = [dfs(n) for n in node.neighbors]

            return new_node
        
        return dfs(node)
