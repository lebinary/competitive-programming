# 323. Number of Connected Components in an Undirected Graph
# Difficulty: Medium
# Status: Accepted
# Runtime: 3 ms (beats 88.7%)
# Memory: 18.6 MB (beats 100.0%)
# Submitted: 2024-11-05 03:33:54 UTC
# URL: https://leetcode.com/submissions/detail/1443387407/

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        mapping = {node:[] for node in range(n)}
        for start, end in edges:
            mapping[start].append(end)
            mapping[end].append(start)
        

        visited = [False] * n
        def dfs(curr):
            if visited[curr]:
                return
            
            visited[curr] = True
            for nxt in mapping[curr]:
                if visited[nxt] == False:
                    dfs(nxt)

        components = 0
        for node in range(n):
            if visited[node] == False:
                dfs(node)
                components += 1

        return components
