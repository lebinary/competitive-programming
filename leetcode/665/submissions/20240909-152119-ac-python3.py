# 665. Non-decreasing Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 143 ms (beats 6.1%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2024-09-09 15:21:19 UTC
# URL: https://leetcode.com/submissions/detail/1384377448/

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                if count == 1: return False
                if i == 0 or nums[i+1] >= nums[i-1]:
                    nums[i] = nums[i+1]
                else:
                    nums[i+1] = nums[i]
                count += 1
        return True

#243 => 233
#342 => 344
