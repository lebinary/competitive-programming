# 1299. Replace Elements with Greatest Element on Right Side
# Difficulty: Easy
# Status: Accepted
# Runtime: 532 ms (beats 5.1%)
# Memory: 14.6 MB (beats 8.8%)
# Submitted: 2023-10-21 05:19:52 UTC
# URL: https://leetcode.com/submissions/detail/1080362226/

class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        mx = -1
        for i in range(len(arr) - 1, -1, -1):
            tmp = arr[i]
            
            arr[i] = mx

            if tmp > mx:
                mx = tmp
        
        return arr



        
