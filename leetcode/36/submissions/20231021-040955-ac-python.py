# 36. Valid Sudoku
# Difficulty: Medium
# Status: Accepted
# Runtime: 50 ms (beats 5.3%)
# Memory: 13.3 MB (beats 24.8%)
# Submitted: 2023-10-21 04:09:55 UTC
# URL: https://leetcode.com/submissions/detail/1080330692/

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)

        for i in range(9):
            for j in range(9):
                curr = board[i][j]

                if curr == ".": continue

                if curr in rows[i]: return False
                else: rows[i].add(curr)
                
                if curr in cols[j]: return False
                else: cols[j].add(curr)

                if curr in boxes[(i // 3, j // 3)]: return False
                else: boxes[(i // 3, j // 3)].add(curr)

        
        return True

                
                 



                

        
