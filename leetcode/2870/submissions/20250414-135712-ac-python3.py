# 2870. Minimum Number of Operations to Make Array Empty
# Difficulty: Medium
# Status: Accepted
# Runtime: 202 ms (beats 5.5%)
# Memory: 66.6 MB (beats 8.2%)
# Submitted: 2025-04-14 13:57:13 UTC
# URL: https://leetcode.com/submissions/detail/1606633211/

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        '''
        Turn array into hash { value -> idx[] }
        Try to apply DEL3 before DEL2
            if value < 2 & value != 0:
                return -1
        '''
        freq_dict = {}
        for num in nums:
            freq_dict[num] = freq_dict.get(num, 0) + 1

        # recrusive to get min operations count for 1 freq
        memo = {}
        def dfs(freq):
            if freq < 0:
                return -1
            if freq == 0:
                return 0
            if freq in memo:
                return memo[freq]

            res1 = dfs(freq - 2)
            res2 = dfs(freq - 3)

            res = -1
            if res1 == -1 and res2 == -1:
                res = -1
            elif res1 == -1:
                res = 1 + res2
            elif res2 == -1:
                res = 1 + res1
            else:
                res = 1 + min(res1, res2)

            memo[freq] = res
            return memo[freq]


        operations_count = 0
        memo = {} 
        for num, freq in freq_dict.items():
            min_count = dfs(freq)
            if min_count == -1:
                return -1
            operations_count += min_count
        return operations_count
