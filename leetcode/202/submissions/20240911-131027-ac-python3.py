# 202. Happy Number
# Difficulty: Easy
# Status: Accepted
# Runtime: 28 ms (beats 3.0%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-11 13:10:27 UTC
# URL: https://leetcode.com/submissions/detail/1386550892/

class Solution:
    def isHappy(self, n: int) -> bool:
        # happy if it ends with only one 1s and many zeros
        # not happy other wise 
        
        # linked list problem: it is guarantee that there is a cycle in the linked list.
        # two scenarios:
        # first: 19 -> 82 -> 68 -> 100 -> 1 -> 1 (endless loop at 1)
        # second: 4 -> 16 -> 37 -> 58 → 89 → 145 → 42 → 20 → 4 (loops back to 4)

        slow = n
        fast = self.sumSquares(n)

        while slow != fast:
            slow = self.sumSquares(slow)
            fast = self.sumSquares(self.sumSquares(fast))

        return True if slow == 1 else False
    
    def sumSquares(self, n: int) -> int:
        sumsquares = 0
        while n > 0:
            sumsquares += (n % 10)**2
            n = n // 10
        return sumsquares
