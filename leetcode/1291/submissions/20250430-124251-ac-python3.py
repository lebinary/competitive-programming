# 1291. Sequential Digits
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2025-04-30 12:42:51 UTC
# URL: https://leetcode.com/submissions/detail/1621953808/

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []

        def dfs(num):
            if num > high:
                return

            if num >= low:
                res.append(num)
  
            last_digit = num % 10
            if last_digit < 9:
                new_num = num * 10 + (last_digit+1) # append to the end
                dfs(new_num)

        for num in range(1, 10):
            dfs(num)
        
        return sorted(res)
