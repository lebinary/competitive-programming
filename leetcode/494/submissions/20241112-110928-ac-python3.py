# 494. Target Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 204 ms (beats 10.8%)
# Memory: 17.4 MB (beats 100.0%)
# Submitted: 2024-11-12 11:09:28 UTC
# URL: https://leetcode.com/submissions/detail/1450510678/

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        if not -sum(nums) <= target <= sum(nums):
            return 0

        n = len(nums)
        dp = [defaultdict(int) for _ in range(n + 1)]
        dp[n][0] = 1  # base case

        for i in range(n - 1, -1, -1):  # Go backwards from n-1 to 0
            curr = nums[i]
            for total, count in dp[i + 1].items():  # Look at next state's values
                # Add the count to both possible next states
                dp[i][total + curr] += count  # Adding current number
                dp[i][total - curr] += count  # Subtracting current number
        print([i.items() for i in dp])
        return dp[0][target]
