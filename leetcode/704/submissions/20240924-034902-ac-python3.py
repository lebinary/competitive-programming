# 704. Binary Search
# Difficulty: Easy
# Status: Accepted
# Runtime: 204 ms (beats 1.8%)
# Memory: 18.3 MB (beats 100.0%)
# Submitted: 2024-09-24 03:49:02 UTC
# URL: https://leetcode.com/submissions/detail/1400271867/

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # rightmost binary search
        l = 0
        r = len(nums)

        while l < r:
            mid = l + (r - l) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid
            else:
                l = mid + 1

        return -1
