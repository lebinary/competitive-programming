# 264. Ugly Number II
# Difficulty: Medium
# Status: Accepted
# Runtime: 295 ms (beats 5.3%)
# Memory: 12.5 MB (beats 69.6%)
# Submitted: 2026-04-30 16:12:37 UTC
# URL: https://leetcode.com/submissions/detail/1991941474/

# hinted used: 4
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        nums = [1]
        seen = set()
        seen.add(1)
        factors = [2, 3, 5]
        
        i = 1
        while nums and i < n:
            num = heapq.heappop(nums)

            for factor in factors:
                new_num = num * factor 
                if new_num not in seen:
                    heapq.heappush(nums, new_num)
                    seen.add(new_num)

            i += 1

        return nums[0]
        
