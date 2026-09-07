# 523. Continuous Subarray Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 912 ms (beats 5.0%)
# Memory: 35.6 MB (beats 98.0%)
# Submitted: 2024-09-13 05:36:59 UTC
# URL: https://leetcode.com/submissions/detail/1388428536/

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # num % k == 0 -> that num is multiple of k
        # hashmap: remainder -> index
        # if curr_num % k is in hashmap:
        #   means whatever elements(subarray) we added since the hashmap key to now is multiple of k
        #   For example: 
        #       hasmap = { remainder(5) -> index(0) }
        #       * now we at current idx 3, and the remainder calculated also 5 *
        #.      => the subarray between idx 0-3 has remainder of 0

        remainder = {0: -1} # in case first element has remainder of 0
        total = 0
        for i, num in enumerate(nums):
            total += num
            r = total % k

            if r in remainder: 
                if i - remainder[r] > 1:
                    return True
                else:
                    continue
            
            remainder[r] = i

        return False
