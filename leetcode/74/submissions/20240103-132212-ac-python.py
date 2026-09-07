# 74. Search a 2D Matrix
# Difficulty: Medium
# Status: Accepted
# Runtime: 24 ms (beats 0.4%)
# Memory: 13.7 MB (beats 2.6%)
# Submitted: 2024-01-03 13:22:12 UTC
# URL: https://leetcode.com/submissions/detail/1135641307/

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        t, b = 0, len(matrix) - 1
        l, r = 0, len(matrix[0]) - 1

        m = -1
        while t <= b:
            m = (t + b) // 2
            
            if matrix[m][-1] < target:
                t = m + 1
            elif matrix[m][0] > target:
                b = m - 1
            else:
                break

        while l <= r:
            n = (l + r) // 2

            if matrix[m][n] < target:
                l = n + 1
            elif matrix[m][n] > target:
                r = n - 1
            else:
                return True
        
        return False

