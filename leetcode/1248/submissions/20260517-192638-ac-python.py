# 1248. Count Number of Nice Subarrays
# Difficulty: Medium
# Status: Accepted
# Runtime: 127 ms (beats 64.8%)
# Memory: 16.1 MB (beats 93.5%)
# Submitted: 2026-05-17 19:26:38 UTC
# URL: https://leetcode.com/submissions/detail/2005840000/

class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        lmin, lmax = 0, 0
        min_odds, max_odds = 0, 0
        
        for r in range(len(nums)):
            if nums[r] % 2 != 0:
                max_odds += 1
                min_odds += 1

            while lmax <= r and max_odds >= k:
                max_odds -= 1 if nums[lmax] % 2 != 0 else 0
                lmax += 1
            
            while lmin <= r and min_odds > k:
                min_odds -= 1 if nums[lmin] % 2 != 0 else 0
                lmin += 1
            
            res += lmax - lmin

        return res
