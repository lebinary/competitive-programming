# 26. Remove Duplicates from Sorted Array
# Difficulty: Easy
# Status: Accepted
# Runtime: 57 ms (beats 5.7%)
# Memory: 13.3 MB (beats 79.3%)
# Submitted: 2024-08-29 10:44:10 UTC
# URL: https://leetcode.com/submissions/detail/1372096001/

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        uniq_idx = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[uniq_idx] = nums[i]
                uniq_idx += 1
    
        return uniq_idx
