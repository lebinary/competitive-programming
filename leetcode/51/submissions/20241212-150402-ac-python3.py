# 51. N-Queens
# Difficulty: Hard
# Status: Accepted
# Runtime: 68 ms (beats 5.0%)
# Memory: 18 MB (beats 100.0%)
# Submitted: 2024-12-12 15:04:02 UTC
# URL: https://leetcode.com/submissions/detail/1477080233/

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        positions = []

        def can_attack(pos1, pos2):
            x1, y1 = pos1
            x2, y2 = pos2

            return (
                x1 == x2 or
                y1 == y2 or
                abs(x1 - x2) == abs(y1 - y2)
            )

        def convert_to_table(positions):
            table = [["."] * n for _ in range(n)]
            for x, y in positions:
                table[x][y] = "Q"
            return [''.join(row) for row in table]
        
        def dfs(i):
            if i >= n:
                res.append(convert_to_table(positions))
                return
            
            for j in range(n):
                cur_pos = (i, j)
                if any(can_attack(prev_pos, cur_pos) for prev_pos in positions):
                    continue

                positions.append(cur_pos)
                dfs(i+1)
                positions.pop()

        dfs(0)
        return res
