# 303. Range Sum Query - Immutable
# Difficulty: Easy
# Status: Accepted
# Runtime: 73 ms (beats 22.4%)
# Memory: 20.1 MB (beats 100.0%)
# Submitted: 2024-09-10 18:36:50 UTC
# URL: https://leetcode.com/submissions/detail/1385748892/

class NumArray:

    def __init__(self, nums: List[int]):
        self.prefixSum = []
        for i in range(len(nums)):
            prefix = self.prefixSum[i - 1] if i > 0 else 0
            self.prefixSum.append(prefix + nums[i])
        print(self.prefixSum)

    def sumRange(self, left: int, right: int) -> int:
        left_prefix = self.prefixSum[left-1] if left > 0 else 0
        return self.prefixSum[right] - left_prefix


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
