# 78. Subsets
# Difficulty: Medium
# Status: Accepted
# Runtime: 44 ms (beats 1.1%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-25 12:48:05 UTC
# URL: https://leetcode.com/submissions/detail/1401825266/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        subset = []
        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return
            
            # left subtree
            subset.append(nums[i]) # left tree node
            dfs(i + 1) # recursive on the next num

            # right subtree
            subset.pop() # right tree node
            dfs(i + 1)  # recursive on the next num
        
        dfs(0)

        return res
