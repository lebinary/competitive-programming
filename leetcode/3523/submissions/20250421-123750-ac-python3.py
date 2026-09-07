# 3523. Make Array Non-decreasing
# Difficulty: Medium
# Status: Accepted
# Runtime: 24 ms (beats 87.7%)
# Memory: 36.4 MB (beats 100.0%)
# Submitted: 2025-04-21 12:37:50 UTC
# URL: https://leetcode.com/submissions/detail/1613523778/

class Solution:
    def maximumPossibleSize(self, nums: List[int]) -> int:
        size, prev = 0, -1

        for num in nums:
            if num >= prev:
                prev = num
                size += 1
        
        return size
                
        
