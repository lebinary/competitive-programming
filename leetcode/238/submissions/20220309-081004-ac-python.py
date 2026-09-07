# 238. Product of Array Except Self
# Difficulty: Medium
# Status: Accepted
# Runtime: 263 ms (beats 5.0%)
# Memory: 23.4 MB (beats 11.8%)
# Submitted: 2022-03-09 08:10:04 UTC
# URL: https://leetcode.com/submissions/detail/656429565/

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        # prefix = [1 , 2 , 6 , 24]
        # postfix =[24, 24, 12, 4 ]
        prefix = []
        for num in nums:
            if len(prefix) > 0:
                prefix.append(num * prefix[-1])
            else:
                prefix.append(num)
                
        postfix = [1] * len(nums)
        for i in range(len(nums)-1, -1, -1):
            if i == len(nums)-1:
                postfix[i] = nums[i]
            else:
                postfix[i] = nums[i] * postfix[i+1]
                
        res = [1] * len(nums)
        for i in range(len(nums)):
            if i == 0:
                res[i] = postfix[i+1]
            elif i == len(nums)-1:
                res[i] = prefix[i-1]
            else:
                res[i] = prefix[i-1] * postfix[i+1]
        
        return res
            
