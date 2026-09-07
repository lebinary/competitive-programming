# 15. 3Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 933 ms (beats 20.2%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2023-12-18 15:30:01 UTC
# URL: https://leetcode.com/submissions/detail/1122687563/

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []

        for i in range(0, len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]: continue

            l = i + 1
            r = len(nums) - 1

            while l < r:
                cur_sum = nums[i] + nums[l] + nums[r]
                if cur_sum == 0:
                    res.append([nums[i], nums[l], nums[r]])

                    # Duplicate checking
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    
                    r -= 1

                elif cur_sum < 0:
                    l += 1
                elif cur_sum > 0:
                    r -=1
        
        return res
        
