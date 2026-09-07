# 347. Top K Frequent Elements
# Difficulty: Medium
# Status: Accepted
# Runtime: 71 ms (beats 7.3%)
# Memory: 15.2 MB (beats 30.0%)
# Submitted: 2024-08-28 18:16:22 UTC
# URL: https://leetcode.com/submissions/detail/1371451682/

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        hash = dict()

        for num in nums:
            if num in hash:
                hash[num] += 1
            else:
                hash[num] = 1

        flatten_arr = [[key, val] for key,val in hash.items()]
        flatten_arr.sort(key=lambda item: item[1], reverse=True)
        
        return [item[0] for item in flatten_arr[:k]]
