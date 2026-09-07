# 238. Product of Array Except Self
# Difficulty: Medium
# Status: Accepted
# Runtime: 180 ms (beats 5.0%)
# Memory: 23.2 MB (beats 13.9%)
# Submitted: 2023-10-18 14:06:42 UTC
# URL: https://leetcode.com/submissions/detail/1078394232/

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)

        l_to_r = [num for num in nums]
        r_to_l = [num for num in nums]
        
        for i in range(1, n):
            l_to_r[i] = l_to_r[i-1] * l_to_r[i]
        
        for i in range(n-2, -1, -1):
            r_to_l[i] = r_to_l[i+1] * r_to_l[i]
        
        res = [1 for i in range(n)]
        for i in range(n):
            left_sum = l_to_r[i-1] if i > 0 else 1
            right_sum = r_to_l[i+1] if i < n-1 else 1

            res[i] = left_sum * right_sum

        return res
        
