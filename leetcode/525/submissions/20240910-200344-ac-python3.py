# 525. Contiguous Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 625 ms (beats 5.3%)
# Memory: 22.1 MB (beats 99.9%)
# Submitted: 2024-09-10 20:03:44 UTC
# URL: https://leetcode.com/submissions/detail/1385826613/

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        # result not neceesarily starts from beginning
        # needs to find way to know best subarray at **each** position
        # solution:
        #.    start_idx = prev index s.t. one_count - (different between 1 and 0 at that idx) == zero_count  
        #.    end_idx = current index  
        #     best_subarray = nums[start_idx : end_idx]

        zero, one = 0, 0
        res = 0
        hashmap = {}    # { one-zero => idx } 
                        #  negative key => removing 0 , positive key => removing 1 
        for i, num in enumerate(nums):
            if num == 0: zero += 1
            else: one += 1

            diff = one - zero
            if diff == 0:
                # subarray starts at begining
                res = one + zero
            else:
                # one > zero or zero > one
                if diff in hashmap:
                    idx = hashmap[diff]
                    res = max(res, i - idx)
                else:
                    hashmap[diff] = i

        return res
