# 210. Course Schedule II
# Difficulty: Medium
# Status: Accepted
# Runtime: 4 ms (beats 47.6%)
# Memory: 18.5 MB (beats 100.0%)
# Submitted: 2024-11-03 04:53:37 UTC
# URL: https://leetcode.com/submissions/detail/1441435798/

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

            # instead of using memo, remove from the courseMap to save space
            del courseMap[course]

            # save result
            res.append(course)
            
            return True

        for course in range(numCourses):
            # detect cycle
            if not dfs(course, set()):
                return []
        return res
