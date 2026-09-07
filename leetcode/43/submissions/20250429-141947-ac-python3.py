# 43. Multiply Strings
# Difficulty: Medium
# Status: Accepted
# Runtime: 62 ms (beats 9.2%)
# Memory: 18 MB (beats 100.0%)
# Submitted: 2025-04-29 14:19:47 UTC
# URL: https://leetcode.com/submissions/detail/1621144599/

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if "0" in [num1, num2]:
            return "0"

        m, n = len(num1), len(num2)
        num1, num2 = num1[::-1], num2[::-1]
        res = [0] * (m + n)

        for i1 in range(m):
            for i2 in range(n):
                prod = int(num1[i1]) * int(num2[i2])
                new_val = res[i1 + i2] + prod

                digit, carry = new_val % 10, new_val // 10
                res[i1 + i2] = digit
                res[i1 + i2 + 1] += carry
        
        res, i = res[::-1], 0
        while i < len(res) and res[i] == 0:
            i += 1
        
        return ''.join(map(str, res[i:]))
