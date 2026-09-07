# 735. Asteroid Collision
# Difficulty: Medium
# Status: Accepted
# Runtime: 153 ms (beats 6.6%)
# Memory: 14.4 MB (beats 7.1%)
# Submitted: 2024-01-02 14:44:20 UTC
# URL: https://leetcode.com/submissions/detail/1134702750/

class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        stack = []

        for a in asteroids:
            stack.append(a)

            while len(stack) >= 2 and stack[-2] >= 0 and stack[-1] <= 0:
                cur_a = stack.pop()
                pre_a = stack.pop()
                if abs(pre_a) < abs(a):
                    stack.append(a)
                elif abs(pre_a) > abs(a):
                    stack.append(pre_a)
        
        return stack
