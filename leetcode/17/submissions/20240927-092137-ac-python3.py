# 17. Letter Combinations of a Phone Number
# Difficulty: Medium
# Status: Accepted
# Runtime: 30 ms (beats 0.1%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-27 09:21:37 UTC
# URL: https://leetcode.com/submissions/detail/1403781969/

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        res = []
        comb = []

        def dfs(i):
            if i == len(digits):
                if len(comb) > 0:
                    res.append("".join(comb.copy()))
                return
            
            for c in mapping[digits[i]]:
                comb.append(c)
                dfs(i + 1)
                comb.pop()
        dfs(0)
        return res
