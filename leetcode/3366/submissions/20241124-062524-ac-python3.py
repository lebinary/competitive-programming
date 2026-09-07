# 3366. Minimum Array Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 2714 ms (beats 9.3%)
# Memory: 232.3 MB (beats 50.0%)
# Submitted: 2024-11-24 06:25:24 UTC
# URL: https://leetcode.com/submissions/detail/1461434634/

class Solution:
    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        def can_op1(num):
            return num > 1
        def can_op2(num):
            return num >= k

        memo = {} # (i, count_op1, count_op2) -> final

        def dfs(i, count_op1, count_op2):
            if i >= len(nums):
                return 0
            if count_op1 == count_op2 == 0:
                return nums[i] + dfs(i+1, 0, 0)
            if (i, count_op1, count_op2) in memo:
                return memo[(i, count_op1, count_op2)]

            res = nums[i]
            final = res + dfs(i+1, count_op1, count_op2)
            if can_op1(res) and count_op1 > 0:
                res1 = (res + 1) // 2
                final = min(final, res1 + dfs(i+1, count_op1 - 1, count_op2))
                
                if can_op2(res1) and count_op2 > 0:
                    res2 = res1 - k
                    final = min(final, res2 + dfs(i+1, count_op1 - 1, count_op2 - 1))

            if can_op2(res) and count_op2 > 0:
                res2 = res - k
                final = min(final, res2 + dfs(i+1, count_op1, count_op2 - 1))
                
                if can_op1(res2) and count_op1 > 0:
                    res1 = (res2 + 1) // 2
                    final = min(final, res1 + dfs(i+1, count_op1 - 1, count_op2 - 1))

            memo[(i, count_op1, count_op2)] = final
            return final

        return dfs(0, op1, op2)
            
