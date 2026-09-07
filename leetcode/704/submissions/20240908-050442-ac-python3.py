# 704. Binary Search
# Difficulty: Easy
# Status: Accepted
# Runtime: 198 ms (beats 1.8%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2024-09-08 05:04:42 UTC
# URL: https://leetcode.com/submissions/detail/1382836724/

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while l <= r:
            m = (l + r) // 2

            if target > nums[m]:
                l = m + 1
            elif target < nums[m]:
                r = m - 1
            else:
                return m

        return -1 
