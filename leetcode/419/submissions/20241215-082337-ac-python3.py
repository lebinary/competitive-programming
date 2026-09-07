# 419. Battleships in a Board
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 19.5 MB (beats 100.0%)
# Submitted: 2024-12-15 08:23:37 UTC
# URL: https://leetcode.com/submissions/detail/1479250648/

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        R, C = len(board), len(board[0])
        ships = 0
        for r in range(R):
            for c in range(C):
                if (
                    board[r][c] == "X" and
                    ((r-1) < 0 or board[r-1][c] != "X") and
                    ((c-1) < 0 or board[r][c-1] != "X")
                ):
                    ships += 1
        return ships
