# 523. Continuous Subarray Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 780 ms (beats 5.1%)
# Memory: 33.3 MB (beats 13.7%)
# Submitted: 2021-09-25 05:43:53 UTC
# URL: https://leetcode.com/submissions/detail/560594374/

"""
similar to Maximum Sum Subarray of Size K https://www.notion.so/paulonteri/Sliding-Window-f6685a15f97a4ca2bb40111e2b264fb2#891e1ba6076b4454a9175a553393f295

    [1, 2, 3, 4,]  <= array
    [1, 3, 6, 10] <= cummulative sums
    10 -1 =  19  = 2+3+4
    6 -1  =   5  = 2+3

if we store the cumulative sum for every point (idx) in the array,
    if (sum2-sum1) % k = 0
    then the numbers between sum2-sum1 add up to a multiple of k

if you find duplicated sum%k values, then that the sub array between those two indexes will actually be the solution.
(sum2-sum1) % k = 0
sum2%k - sum1%k = 0
sum2%k = sum1%k
remainder2 = remainder1

"""

class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        currentSum = 0
        
        #HashMap format is {remainder, indexAtThatSum} 
        dic = {0 : -1}
        
        for i, num in enumerate(nums):
            currentSum += num
            remainder = currentSum % k
            
            #check count logic
            if remainder in dic and i - dic[remainder] >= 2:
                return True
            
            #update prefixSum logic
            if remainder not in dic:
                dic[remainder] = i
        return False
