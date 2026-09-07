# 416. Partition Equal Subset Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 633 ms (beats 72.3%)
# Memory: 157.4 MB (beats 19.8%)
# Submitted: 2024-10-26 12:21:13 UTC
# URL: https://leetcode.com/submissions/detail/1434173700/

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total_sum = sum(nums)
        if total_sum % 2:
            return False

        @lru_cache(maxsize=None)
        def dfs(i: int, target: int) -> bool:
            if target == 0:
                return True
            if i >= len(nums) or target < 0:
                return False

            return dfs(i+1, target - nums[i]) or dfs(i+1, target)

        return dfs(0, total_sum // 2)
