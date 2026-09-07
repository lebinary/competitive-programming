# 207. Course Schedule
# Difficulty: Medium
# Status: Accepted
# Runtime: 7 ms (beats 43.6%)
# Memory: 18.4 MB (beats 100.0%)
# Submitted: 2024-11-02 11:23:15 UTC
# URL: https://leetcode.com/submissions/detail/1440710851/

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courseMap = {}

        for k, v in prerequisites:
            if k not in courseMap:
                courseMap[k] = [] 
            courseMap[k].append(v)

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

            return True

        for course in range(numCourses):
            # detect cycle
            if not dfs(course, set()):
                return False
        return True
