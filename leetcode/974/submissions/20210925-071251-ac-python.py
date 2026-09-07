# 974. Subarray Sums Divisible by K
# Difficulty: Medium
# Status: Accepted
# Runtime: 276 ms (beats 5.7%)
# Memory: 16.7 MB (beats 5.8%)
# Submitted: 2021-09-25 07:12:51 UTC
# URL: https://leetcode.com/submissions/detail/560627602/

"""
if cumulative sum at j - cumulative sum at i =  k
then sum of all elements between i and j has sum of k

We want sum between i and j is divisible by k:
(sum2 - sum1) % k = 0
sum2%k - sum1%k = 0
sum2%k = sum1%k
remainder2 = remainder1

We have to store all cumulative remainder in hashmap in format = {prefix_remainder, number of occurence}
"""

class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cumSum = 0
        remainders = {0: 1}
        count = 0
        
        for i, num in enumerate(nums):
            cumSum += num
            remainder = cumSum % k
            
            if remainder in remainders:
                count += remainders[remainder]
                remainders[remainder] += 1
                
            else: remainders[remainder] = 1
        return count
        
                
            
        
