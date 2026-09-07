# 560. Subarray Sum Equals K
# Difficulty: Medium
# Status: Accepted
# Runtime: 223 ms (beats 5.4%)
# Memory: 19.4 MB (beats 100.0%)
# Submitted: 2024-09-11 04:17:00 UTC
# URL: https://leetcode.com/submissions/detail/1386114322/

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        hashmap = {}

        curr_sum = 0
        for i in range(len(nums)):
            # map prefix sum -> number of occurences
            hashmap[curr_sum] = 1 + hashmap.get(curr_sum, 0)
            
            curr_sum += nums[i]
            # number of occurences in hashmap == number of subarrays at this position
            if curr_sum - k in hashmap:
                res += hashmap[curr_sum - k]

        return res
