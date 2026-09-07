# 303. Range Sum Query - Immutable
# Difficulty: Easy
# Status: Accepted
# Runtime: 72 ms (beats 22.4%)
# Memory: 20.2 MB (beats 100.0%)
# Submitted: 2024-09-10 18:39:55 UTC
# URL: https://leetcode.com/submissions/detail/1385752217/

class NumArray:

    def __init__(self, nums: List[int]):
        self.prefixSum = [0 for i in range(len(nums) + 1)]
        for i in range(len(nums)):
            self.prefixSum[i+1] = nums[i] + self.prefixSum[i] 
        print(self.prefixSum)

    def sumRange(self, left: int, right: int) -> int:
        return self.prefixSum[right+1] - self.prefixSum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
