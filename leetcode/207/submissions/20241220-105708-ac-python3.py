# 207. Course Schedule
# Difficulty: Medium
# Status: Accepted
# Runtime: 8 ms (beats 21.5%)
# Memory: 19.5 MB (beats 100.0%)
# Submitted: 2024-12-20 10:57:08 UTC
# URL: https://leetcode.com/submissions/detail/1483683414/

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mapping = {c:[] for c in range(numCourses)}
        for course, prereq in prerequisites:
            mapping[course].append(prereq)
        
        visited = set()
        def dfs(course):
            if course not in mapping:
                return True
            if course in visited:
                return False
            
            visited.add(course)
            for prereq in mapping[course]:
                if not dfs(prereq):
                    return False
            visited.remove(course)

            mapping[course] = []
            return True
        
        for course in range(numCourses):
            if course not in visited and not dfs(course):
                return False
        return True
