# 1769. Minimum Number of Operations to Move All Balls to Each Box
# Difficulty: Medium
# Status: Accepted
# Runtime: 3157 ms (beats 7.2%)
# Memory: 18 MB (beats 100.0%)
# Submitted: 2025-05-03 10:45:47 UTC
# URL: https://leetcode.com/submissions/detail/1624320292/

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n

        for i in range(n):
            # l -> r
            for j in range(i+1, n):
                if boxes[j] == "1":
                    res[i] += abs(i-j)

            # r -> l
            for j in range(i-1, -1, -1):
                if boxes[j] == "1":
                    res[i] += abs(i-j)
        
        return res
