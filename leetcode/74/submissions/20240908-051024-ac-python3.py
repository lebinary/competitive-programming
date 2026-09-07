# 74. Search a 2D Matrix
# Difficulty: Medium
# Status: Accepted
# Runtime: 49 ms (beats 0.0%)
# Memory: 17.1 MB (beats 100.0%)
# Submitted: 2024-09-08 05:10:24 UTC
# URL: https://leetcode.com/submissions/detail/1382841175/

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = 0

        t = 0
        b = len(matrix) - 1
        while t <= b:
            m = (t + b) // 2
            if target > matrix[m][-1]:
                t = m + 1
            elif target < matrix[m][0]:
                b = m - 1
            else:
                row = m
                break

        l = 0
        r = len(matrix[0]) - 1
        while l <= r:
            m = (l + r) // 2
            if target > matrix[row][m]:
                l = m + 1
            elif target < matrix[row][m]:
                r = m - 1
            else:
                return True
        
        return False
