# 3522. Calculate Score After Performing Instructions
# Difficulty: Medium
# Status: Accepted
# Runtime: 25 ms (beats 36.7%)
# Memory: 44.9 MB (beats 23.4%)
# Submitted: 2025-04-20 09:40:26 UTC
# URL: https://leetcode.com/submissions/detail/1612382472/

class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        n = len(instructions)
        executed = set()
        score = 0

        i = 0
        while 0 <= i < n:
            if i in executed:
                break
            executed.add(i)
            
            if instructions[i] == "jump":
                i += values[i]
            else:
                score += values[i]
                i += 1
                
        return score
