# 560. Subarray Sum Equals K
# Difficulty: Medium
# Status: Accepted
# Runtime: 192 ms (beats 5.3%)
# Memory: 16.1 MB (beats 5.7%)
# Submitted: 2021-09-25 04:07:25 UTC
# URL: https://leetcode.com/submissions/detail/560560139/

class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Solution: keep tracks of how many previous subarrays 
        # you can remove to get the array with sum = k
        # Example: There are 2 ways to remove previous subarrays to get 
        # array sum = k  => There are 2 subarrays in that array that has sum = k
        
        currentSum = 0
        count = 0
        dic = dict()
        
        #Set default prefixSum
        dic[currentSum] = 1
        
        for num in nums:
            currentSum += num
            
            if currentSum-k in dic: count += dic[currentSum-k]
                
            if currentSum in dic: dic[currentSum] += 1
            else: dic[currentSum] = 1
                
        return count
                
