# 88. Merge Sorted Array
# Difficulty: Easy
# Status: Accepted
# Runtime: 39 ms (beats 1.5%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-23 13:49:45 UTC
# URL: https://leetcode.com/submissions/detail/1399612856/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        while m > 0 and n > 0:
            if nums1[m-1] >= nums2[n-1]:
                nums1[m+n-1] = nums1[m-1]
                m -= 1
            else:
                nums1[m+n-1] = nums2[n-1]
                n -= 1
                
        if n > 0:
            nums1[:n] = nums2[:n]
