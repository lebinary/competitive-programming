# 219. Contains Duplicate II
# Difficulty: Easy
# Status: Accepted
# Runtime: 497 ms (beats 5.0%)
# Memory: 22.1 MB (beats 100.0%)
# Submitted: 2023-12-22 15:58:53 UTC
# URL: https://leetcode.com/submissions/detail/1125971575/

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        l = 0
        num_set = set()

        for r in range(0, len(nums)):
            if nums[r] in num_set:
                return True
            else:
                num_set.add(nums[r])
            
            # shrink window
            if r - l == k:
                num_set.remove(nums[l])
                l += 1

        return False  
            
        
