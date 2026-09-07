# 261. Graph Valid Tree
# Difficulty: Medium
# Status: Accepted
# Runtime: 7 ms (beats 13.0%)
# Memory: 18.5 MB (beats 100.0%)
# Submitted: 2024-11-04 05:16:11 UTC
# URL: https://leetcode.com/submissions/detail/1442404727/

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        mapping = {node: [] for node in range(n)}
        for start, end in edges:
            mapping[start].append(end)
            mapping[end].append(start)
        

        visited = set()

        def dfs(prev, curr):
            if curr in visited:
                return False
            
            visited.add(curr)
            for nxt in mapping[curr]:
                if nxt == prev:
                    continue
                elif not dfs(curr, nxt):
                    return False
            
            return True
        
        return dfs(-1, 0) and len(visited) == n
