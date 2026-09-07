# 238. Product of Array Except Self
# Difficulty: Medium
# Status: Accepted
# Runtime: 317 ms (beats 5.0%)
# Memory: 20.5 MB (beats 35.2%)
# Submitted: 2022-02-11 13:20:27 UTC
# URL: https://leetcode.com/submissions/detail/639272384/

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        
        answer = [1]*n
        
        for i in range(1, n):
            answer[i] = answer[i-1] * nums[i-1]
            
        # ans = [1, 1, 2, 6]
        
        post = 1
        for i in range(n-2, -1, -1):
            post *= nums[i+1]
            answer[i] = answer[i] * post
        
        return answer
        
