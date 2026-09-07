# 42. Trapping Rain Water
# Difficulty: Hard
# Status: Accepted
# Runtime: 12 ms (beats 30.1%)
# Memory: 22.6 MB (beats 7.0%)
# Submitted: 2026-04-28 14:00:59 UTC
# URL: https://leetcode.com/submissions/detail/1990264745/

class Solution:
    def trap(self, height: List[int]) -> int:
        q = [(0, -1)]
        total = 0

        for i, h in enumerate(height):
            while len(q) > 1 and q[-1][0] < h:
                (prev_h, prev_i) = q.pop()
                hei = max(0, min(h, q[-1][0]) - prev_h)
                wid = i - q[-1][1] - 1
                total += hei * wid
            
            q.append((h, i))
        
        return total
