# 912. Sort an Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 1131 ms (beats 5.0%)
# Memory: 24.6 MB (beats 100.0%)
# Submitted: 2024-09-18 10:59:43 UTC
# URL: https://leetcode.com/submissions/detail/1394263019/

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        # sort [5 2 3 1]

        # sort left [5 2]
            # sort left [5]
                # base case: return
            # sort right [2]
                # base case: return
            # merge([5], [2])
            # return [2, 5]

        # sort right [3 1]
            # sort left: [3]
                # base case: return
            # sort right: [1]
                # base case: return
            # merge([3], [1])
            # return [1, 3]
        
        # merge([2, 5], [1, 3])
        # return [1 2 3 5]

        if len(nums) == 1:
            return nums
        
        m = len(nums) // 2
        sorted_left = self.sortArray(nums[:m])
        sorted_right = self.sortArray(nums[m:])

        return self.merge(sorted_left, sorted_right)

    def merge(self, left: List[int], right: List[int]) -> List[int]:
        L = len(left)
        R = len(right)
        arr = [0] * (L + R)

        i = 0
        l = 0
        r = 0
        while l < L and r < R:
            if left[l] < right[r]:
                arr[i] = left[l]
                l += 1
            else:
                arr[i] = right[r]
                r += 1
            i += 1

        if l < L:
            while i < len(arr):
                arr[i] = left[l]
                l += 1
                i += 1
        elif r < R:
            while i < len(arr):
                arr[i] = right[r]
                r += 1
                i += 1
        
        return arr

        

