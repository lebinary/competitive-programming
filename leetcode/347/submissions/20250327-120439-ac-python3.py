# 347. Top K Frequent Elements
# Difficulty: Medium
# Status: Accepted
# Runtime: 5 ms (beats 61.8%)
# Memory: 21.3 MB (beats 100.0%)
# Submitted: 2025-03-27 12:04:40 UTC
# URL: https://leetcode.com/submissions/detail/1588061365/

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        hm = dict()

        for num in nums:
            hm[num] = 1 + hm.get(num, 0)

        arr = [(k, v) for k, v in hm.items()]
        sorted_arr = sorted(arr, key=lambda x: x[1], reverse=True)

        return [k for k, _ in sorted_arr[:k]]
