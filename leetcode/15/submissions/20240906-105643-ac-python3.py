# 15. 3Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 676 ms (beats 28.7%)
# Memory: 20.7 MB (beats 100.0%)
# Submitted: 2024-09-06 10:56:43 UTC
# URL: https://leetcode.com/submissions/detail/1380978349/

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i, num in enumerate(nums):
            if i > 0 and num == nums[i-1]: continue

            l = i + 1
            r = len(nums) - 1

            while l < r:
                three_sum = num + nums[l] + nums[r]

                if three_sum == 0:
                    res.append([num, nums[l], nums[r]])

                    while l < r and nums[l] == nums[l+1]:
                        l += 1
                    l += 1
                    
                    while l < r and nums[r] == nums[r-1]:
                        r -= 1
                    r -= 1

                elif three_sum > 0:
                    r -= 1
                else:
                    l += 1

        return res
