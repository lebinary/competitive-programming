# 46. Permutations
# Difficulty: Medium
# Status: Accepted
# Runtime: 33 ms (beats 1.9%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-26 04:18:18 UTC
# URL: https://leetcode.com/submissions/detail/1402524166/

class Solution:
    # complexity:
    #   . number of permutations: n!
    #   . for each permutation: n 
    #   . p_copy.insert for each position: n
    # => n! * n * n
    def permute(self, nums: List[int]) -> List[List[int]]:
        # base case
        if len(nums) <= 0:
            return [[]]
        
        res = []
        curr = nums[0]

        permutations = self.permute(nums[1:])
        for p in permutations:
            # insert curr in all possible positions in permutation
            for i in range(len(p) + 1):
                p_copy = p.copy()
                p_copy.insert(i, curr)
                res.append(p_copy)
        
        return res
