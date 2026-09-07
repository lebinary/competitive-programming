# 684. Redundant Connection
# Difficulty: Medium
# Status: Accepted
# Runtime: 5 ms (beats 24.5%)
# Memory: 17.4 MB (beats 100.0%)
# Submitted: 2024-11-05 05:58:29 UTC
# URL: https://leetcode.com/submissions/detail/1443507472/

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # detect cycle, return the last edge that form the cycle
        mapping = {} 
        for start, end in edges:
            if start not in mapping:
                mapping[start] = []
            if end not in mapping:
                mapping[end] = []
            mapping[start].append(end)
            mapping[end].append(start)

        visited = set()
        cycle = set() # store all the vertices involved in the creating the cycle
        cycleStart = -1 # to mark when to stop adding to "cycle"

        # can also do dfs, but Im trying bfs for fun
        def dfs(prev, curr):
            nonlocal cycleStart
            if curr in visited:
                cycleStart = curr
                return True
            
            visited.add(curr)
            for nxt in mapping[curr]:
                if prev == nxt:
                    continue
                elif dfs(curr, nxt):
                    # add the path that create the cycle to "cycle"
                    if cycleStart != -1:
                        cycle.add(curr)
                    if curr == cycleStart: # stop adding
                        cycleStart = -1
                    return True

            return False
            
        dfs(-1, 1)

        for u, v in reversed(edges):
            if u in cycle and v in cycle:
                return [u, v]

        return []
