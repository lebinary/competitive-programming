# 1769. Minimum Number of Operations to Move All Balls to Each Box
# Difficulty: Medium
# Status: Accepted
# Runtime: 3208 ms (beats 6.3%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2025-05-03 10:57:44 UTC
# URL: https://leetcode.com/submissions/detail/1624327578/

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n

        prefix_l = [0] * n 
        for i in range(n):
            for j in range(i+1, n):
                if boxes[j] == "1":
                    prefix_l[i] += abs(i-j)

        prefix_r = [0] * n
        for i in range(n-1, -1, -1):
            for j in range(i-1, -1, -1):
                if boxes[j] == "1":
                    prefix_r[i] += abs(i-j)
        
        for i in range(n):
            res[i] = prefix_l[i] + prefix_r[i]
        
        return res
