# 210. Course Schedule II
# Difficulty: Medium
# Status: Accepted
# Runtime: 1 ms (beats 82.9%)
# Memory: 18.4 MB (beats 100.0%)
# Submitted: 2024-11-03 05:05:43 UTC
# URL: https://leetcode.com/submissions/detail/1441443835/

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        courseMap = {c: [] for c in range(numCourses)}
        for crs, pre in prerequisites:
            courseMap[crs].append(pre)

        res = []

        # Recursive func to dectect cycle
        def dfs(course, visited):
            if course in visited:
                return False
            # if course is not in courseMap, it has no prequesite or has already been checked
            if course not in courseMap:
                return True

            visited.add(course)

            # check all the path
            for preq_course in courseMap[course]:
                if not dfs(preq_course, visited):
                    return False
            
            # when done, make sure to remove from visiting path
            # to not contaminate the graph checking
            # i.e right branch should not have "visited" from left branch
            visited.remove(course)

            # Moving course from courseMap to result
            del courseMap[course]
            res.append(course)
            
            return True

        for course in range(numCourses):
            # detect cycle
            if not dfs(course, set()):
                return []
        return res
