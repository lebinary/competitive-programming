# 1769. Minimum Number of Operations to Move All Balls to Each Box
# Difficulty: Medium
# Status: Accepted
# Runtime: 11 ms (beats 63.4%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2025-05-03 11:15:54 UTC
# URL: https://leetcode.com/submissions/detail/1624338590/

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        res = [0] * n

        balls = moves = 0
        for i in range(n):
            res[i] += balls + moves
            moves += balls
            balls += int(boxes[i])

        balls = moves = 0
        for i in range(n-1, -1, -1):
            res[i] += balls + moves
            moves += balls
            balls += int(boxes[i])
        
        return res
