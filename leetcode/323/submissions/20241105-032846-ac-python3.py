# 323. Number of Connected Components in an Undirected Graph
# Difficulty: Medium
# Status: Accepted
# Runtime: 3 ms (beats 88.7%)
# Memory: 18.9 MB (beats 100.0%)
# Submitted: 2024-11-05 03:28:46 UTC
# URL: https://leetcode.com/submissions/detail/1443383840/

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        mapping = {node:[] for node in range(n)}
        for start, end in edges:
            mapping[start].append(end)
            mapping[end].append(start)
        

        visited = set()
        def dfs(prev, curr):
            if curr in visited:
                return
            
            visited.add(curr)
            for nxt in mapping[curr]:
                if nxt != prev:
                    dfs(curr, nxt)

        components = 0
        for node in range(n):
            if node not in visited:
                dfs(-1, node)
                components += 1

        return components
