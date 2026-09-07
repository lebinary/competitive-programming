# 167. Two Sum II - Input Array Is Sorted
# Difficulty: Medium
# Status: Accepted
# Runtime: 102 ms (beats 11.8%)
# Memory: 14.3 MB (beats 6.2%)
# Submitted: 2023-12-18 15:01:18 UTC
# URL: https://leetcode.com/submissions/detail/1122667480/

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = 0
        r = len(numbers) - 1

        while l < r:
            cur_sum = numbers[l] + numbers[r]
            if cur_sum == target:
                return [l+1, r+1]
            elif cur_sum < target:
                l += 1
            elif cur_sum > target:
                r -= 1
        
