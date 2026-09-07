# 496. Next Greater Element I
# Difficulty: Easy
# Status: Accepted
# Runtime: 46 ms (beats 9.6%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-12 11:47:16 UTC
# URL: https://leetcode.com/submissions/detail/1387616824/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hm = {}
        for i, num in enumerate(nums1):
            hm[num] = i
        
        stack = []
        for i, num in enumerate(nums2):
            while stack and num > stack[-1]:
                key = stack.pop()

                if key in hm:
                    nums1[hm[key]] = num
        
            stack.append(num)
        
        for key in stack:
            if key in hm:
                nums1[hm[key]] = -1

        return nums1
