# 3364. Minimum Positive Sum Subarray
# Difficulty: Easy
# Status: Accepted
# Runtime: 87 ms (beats 24.9%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-11-24 04:50:45 UTC
# URL: https://leetcode.com/submissions/detail/1461374949/

class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        min_sum = float('inf')

        for rang in range(l, r+1):
            if rang > n:
                continue
                
            for i in range(0, n-rang+1):
                total = sum(nums[i:i+rang])
                if total > 0:
                    min_sum = min(min_sum, total)

        return min_sum if min_sum != float('inf') else -1
                
