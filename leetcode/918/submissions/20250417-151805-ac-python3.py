# 918. Maximum Sum Circular Subarray
# Difficulty: Medium
# Status: Accepted
# Runtime: 90 ms (beats 5.1%)
# Memory: 21.2 MB (beats 100.0%)
# Submitted: 2025-04-17 15:18:05 UTC
# URL: https://leetcode.com/submissions/detail/1609640702/

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        global_max, global_min = nums[0], nums[0]
        curr_max, curr_min = 0, 0
        total = 0

        for num in nums:
            curr_max = max(curr_max, 0) + num
            curr_min = min(curr_min, 0) + num
            
            global_max = max(global_max, curr_max)
            global_min = min(global_min, curr_min)
            total += num
        
        if(total == global_min):
            return global_max

        return max(global_max, total - global_min)
