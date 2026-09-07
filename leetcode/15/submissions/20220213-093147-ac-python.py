# 15. 3Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 585 ms (beats 90.6%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2022-02-13 09:31:47 UTC
# URL: https://leetcode.com/submissions/detail/640467316/

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        print(nums)
           
        for i in range(0, len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]: continue 
            
            l = i+1
            r = len(nums)-1
            
            while l < r:
                threeSum = nums[i] + nums[l] + nums[r] 
                
                if threeSum > 0 : r-= 1
                elif threeSum < 0: l+= 1
                else: 
                    res.append([nums[i], nums[l], nums[r]])
                    
                    l+=1
                    while nums[l] == nums[l-1] and l < r:
                        l+=1
                
        return res
