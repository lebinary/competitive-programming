# 287. Find the Duplicate Number
# Difficulty: Medium
# Status: Accepted
# Runtime: 456 ms (beats 5.0%)
# Memory: 30.8 MB (beats 100.0%)
# Submitted: 2024-09-11 12:42:47 UTC
# URL: https://leetcode.com/submissions/detail/1386527473/

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # find intersection of slow and fast pointers
        slow = 0
        fast = 0
        while True:
            fast = nums[nums[fast]]
            slow = nums[slow]
            
            if slow == fast:
                break

        # find beginning of cycle
        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            
            if slow == slow2:
                return slow
            
