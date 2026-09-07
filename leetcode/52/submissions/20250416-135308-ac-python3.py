# 52. N-Queens II
# Difficulty: Hard
# Status: Accepted
# Runtime: 83 ms (beats 5.2%)
# Memory: 18 MB (beats 100.0%)
# Submitted: 2025-04-16 13:53:09 UTC
# URL: https://leetcode.com/submissions/detail/1608571305/

class Solution:
    def totalNQueens(self, n: int) -> int:
        def canAttack(pos1, pos2):
            r1, c1 = pos1
            r2, c2 = pos2
            return r1 == r2 or c1 == c2 or abs(r2-r1) == abs(c2-c1)
        
        positions = []
        res = 0
        def backtrack(r):
            nonlocal res
            if r >= n:
                res += 1
                return

            for c in range(n):
                curr_pos = (r, c)
                if any([canAttack(prev_pos, curr_pos) for prev_pos in positions]):
                    continue

                positions.append(curr_pos)
                backtrack(r+1)
                positions.pop()
        
        backtrack(0)
        return res
