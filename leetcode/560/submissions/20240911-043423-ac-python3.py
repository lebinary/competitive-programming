# 560. Subarray Sum Equals K
# Difficulty: Medium
# Status: Accepted
# Runtime: 224 ms (beats 5.4%)
# Memory: 19.5 MB (beats 100.0%)
# Submitted: 2024-09-11 04:34:23 UTC
# URL: https://leetcode.com/submissions/detail/1386128785/

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        prefixSum = {0: 1} # inittial prefix 0
        curr_sum = 0
        
        for num in nums:
            curr_sum += num

            # number of occurences in hashmap == number of subarrays at this position
            # i.e: curr_sum(4) - k(3) = 1. 
            # If prefixSum[1] = 2, means there are 2 ways to make curr_sum(4) = k(3) 
            if curr_sum - k in prefixSum:
                res += prefixSum[curr_sum - k]

            # store the prefix sum
            prefixSum[curr_sum] = 1 + prefixSum.get(curr_sum, 0)
            
        return res
            
