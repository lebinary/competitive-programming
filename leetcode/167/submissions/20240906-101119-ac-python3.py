# 167. Two Sum II - Input Array Is Sorted
# Difficulty: Medium
# Status: Accepted
# Runtime: 103 ms (beats 7.1%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2024-09-06 10:11:19 UTC
# URL: https://leetcode.com/submissions/detail/1380943854/

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1

        while l < r:
          if numbers[l] + numbers[r] == target:
            return [l+1, r+1]
          elif numbers[l] + numbers[r] > target:
            r -= 1
          else:
            l += 1
