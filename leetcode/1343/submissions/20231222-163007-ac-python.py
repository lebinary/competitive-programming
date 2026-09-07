# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
# Difficulty: Medium
# Status: Accepted
# Runtime: 474 ms (beats 5.1%)
# Memory: 23.7 MB (beats 21.3%)
# Submitted: 2023-12-22 16:30:07 UTC
# URL: https://leetcode.com/submissions/detail/1125992284/

class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        res = 0
        total = 0
        l = 0
        for r in range(len(arr)):
            curr_len = r - l + 1
            total += arr[r]

            if curr_len == k:
                # update result
                res += 1 if total/curr_len >= threshold else 0

                # shrink window
                total -= arr[l]
                l += 1

        return res
        
