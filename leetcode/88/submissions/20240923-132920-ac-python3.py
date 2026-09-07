# 88. Merge Sorted Array
# Difficulty: Easy
# Status: Accepted
# Runtime: 35 ms (beats 1.5%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-23 13:29:20 UTC
# URL: https://leetcode.com/submissions/detail/1399593958/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p1 = m - 1
        p2 = n - 1

        for p in range(m + n - 1, -1, -1):
            if p2 < 0:
                break
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
