# 347. Top K Frequent Elements
# Difficulty: Medium
# Status: Accepted
# Runtime: 77 ms (beats 7.0%)
# Memory: 19 MB (beats 26.3%)
# Submitted: 2024-08-28 18:14:43 UTC
# URL: https://leetcode.com/submissions/detail/1371449770/

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        count = {}
        freq = [[] for i in range(len(nums) + 1)]

        for num in nums:
            count[num] = 1 + count.get(num, 0)
        
        for num, count in count.items():
            freq[count].append(num)

        res = []
        for count in range(len(freq) - 1, 0, -1):
            for num in freq[count]:
                res.append(num)
                if len(res) == k: return res 
