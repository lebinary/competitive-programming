# 303. Range Sum Query - Immutable
# Difficulty: Easy
# Status: Accepted
# Runtime: 76 ms (beats 22.4%)
# Memory: 20.2 MB (beats 100.0%)
# Submitted: 2024-09-10 18:42:08 UTC
# URL: https://leetcode.com/submissions/detail/1385754541/

class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix = []
        cur = 0
        for num in nums:
            cur += num
            self.prefix.append(cur)

    def sumRange(self, left: int, right: int) -> int:
        r = self.prefix[right]
        l = self.prefix[left - 1] if left > 0 else 0 
        return r - l


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
