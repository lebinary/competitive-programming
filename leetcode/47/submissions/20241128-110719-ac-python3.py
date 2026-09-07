# 47. Permutations II
# Difficulty: Medium
# Status: Accepted
# Runtime: 18 ms (beats 17.0%)
# Memory: 18.1 MB (beats 100.0%)
# Submitted: 2024-11-28 11:07:19 UTC
# URL: https://leetcode.com/submissions/detail/1464952488/

from collections import Counter

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        
        res = []
        perm = []
        counter = Counter(nums)

        def dfs():
            print(perm)
            if len(perm) >= n:
                res.append(perm.copy())
                return

            for i in range(n):
                if i > 0 and nums[i] == nums[i-1]:
                    continue

                if counter[nums[i]] > 0:
                    counter[nums[i]] -= 1

                    # actual traversal
                    perm.append(nums[i])
                    dfs()
                    perm.pop()

                    counter[nums[i]] += 1

        dfs()
        return res
