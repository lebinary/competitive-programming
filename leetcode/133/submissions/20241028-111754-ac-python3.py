# 133. Clone Graph
# Difficulty: Medium
# Status: Accepted
# Runtime: 41 ms (beats 94.1%)
# Memory: 17 MB (beats 100.0%)
# Submitted: 2024-10-28 11:17:54 UTC
# URL: https://leetcode.com/submissions/detail/1436134957/

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

        # first pass: copy the nodes only, save the reference to hashmap
        visited = set()
        stack = [node]
        # mark as visited
        visited.add(node)
        while stack:
            curr = stack.pop()


            # create new node and save reference to hashmap
            hm[curr] = Node(curr.val)

            # do the same for neighbor nodes
            for neighbor in curr.neighbors:
                if neighbor not in visited:
                    stack.append(neighbor)
                    visited.add(neighbor)

        # second pass: copy the relationships
        visited.clear()
        stack = [node]
        visited.add(node)
        while stack:
            curr = stack.pop()

            # copy relationships from curr node to new node
            new_node = hm[curr]
            for neighbor in curr.neighbors:
                new_node.neighbors.append(hm[neighbor])

                # do the same for neighbor nodes
                if neighbor not in visited:
                    stack.append(neighbor)
                    visited.add(neighbor)
        
        return hm[node]
