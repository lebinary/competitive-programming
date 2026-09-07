# 17. Letter Combinations of a Phone Number
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.3 MB (beats 100.0%)
# Submitted: 2024-12-12 12:10:11 UTC
# URL: https://leetcode.com/submissions/detail/1476964245/

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mapping = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }
        
        n = len(digits)
        res, comb = [], []

        def dfs(i):
            if i >= n:
                if len(comb) > 0:
                    res.append(''.join(comb))
                return
            
            for letter in mapping[digits[i]]:
                comb.append(letter)
                dfs(i+1)
                comb.pop()
        dfs(0)
        return res
