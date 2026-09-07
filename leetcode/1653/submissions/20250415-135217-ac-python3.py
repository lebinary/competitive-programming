# 1653. Minimum Deletions to Make String Balanced
# Difficulty: Medium
# Status: Accepted
# Runtime: 527 ms (beats 15.8%)
# Memory: 19.6 MB (beats 100.0%)
# Submitted: 2025-04-15 13:52:18 UTC
# URL: https://leetcode.com/submissions/detail/1607579940/

class Solution:
    def minimumDeletions(self, s: str) -> int:
        s_arr = list(s)

        a_right_count = sum(1 for char in s_arr if char == 'a')
        b_left_count = 0
        res = min(a_right_count, len(s_arr) - a_right_count)

        for i in range(len(s_arr)):
            if s_arr[i] == 'b':
                b_left_count += 1
            elif s_arr[i] == 'a':
                a_right_count -= 1

            res = min(res, a_right_count + b_left_count)
        return res
        
