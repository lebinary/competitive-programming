# 210. Course Schedule II
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 19.4 MB (beats 100.0%)
# Submitted: 2024-12-20 12:06:17 UTC
# URL: https://leetcode.com/submissions/detail/1483719660/

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        mapping = {c:[] for c in range(numCourses)}
        for course, prereq in prerequisites:
            mapping[course].append(prereq)
        
        res = []
        visited = set()
        def dfs(course):
            if course in visited:
                return False
            if course not in mapping:
                return True
            
            visited.add(course)
            for prereq in mapping[course]:
                if not dfs(prereq):
                    return False

            visited.remove(course)
            res.append(course)
            del mapping[course]
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return []
        return res
