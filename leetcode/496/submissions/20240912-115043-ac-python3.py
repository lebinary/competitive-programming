# 496. Next Greater Element I
# Difficulty: Easy
# Status: Accepted
# Runtime: 56 ms (beats 8.3%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-12 11:50:43 UTC
# URL: https://leetcode.com/submissions/detail/1387619134/

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # map nums1 -> index for easy access
        hm = {}
        for i, num in enumerate(nums1):
            hm[num] = i
        
        res = [-1] * len(nums1)
        
        stack = []
        for i, num in enumerate(nums2):
            while stack and num > stack[-1]:
                key = stack.pop()
                res[hm[key]] = num
        
            if num in hm:
                stack.append(num)

        return res
