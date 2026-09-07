# 47. Permutations II
# Difficulty: Medium
# Status: Accepted
# Runtime: 7 ms (beats 39.5%)
# Memory: 17.6 MB (beats 100.0%)
# Submitted: 2024-11-28 11:19:34 UTC
# URL: https://leetcode.com/submissions/detail/1464958586/

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        
        res = []
        perm = []
        counter = Counter(nums)

        def dfs():
            if len(perm) >= len(nums):
                res.append(perm.copy())
                return

            for uniq_num in counter.keys():
                if counter[uniq_num] > 0:
                    counter[uniq_num] -= 1

                    # actual traversal
                    perm.append(uniq_num)
                    dfs()
                    perm.pop()

                    counter[uniq_num] += 1

        dfs()
        return res
