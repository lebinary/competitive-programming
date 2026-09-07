# 3170. Lexicographically Minimum String After Removing Stars
# Difficulty: Medium
# Status: Accepted
# Runtime: 1843 ms (beats 8.3%)
# Memory: 24.4 MB (beats 33.3%)
# Submitted: 2026-04-30 16:50:54 UTC
# URL: https://leetcode.com/submissions/detail/1991969704/

"""
aaba*baba*

aab baba *
aab bab *
"""

class Solution(object):
    def clearStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        char_heap = []
        index_heap = []
        result = ""
        
        for i, char in enumerate(s):
            if char != "*":
                heapq.heappush(char_heap, (char, -i))
            elif char_heap:
                heapq.heappop(char_heap)
        
        while char_heap:
            char, i = heapq.heappop(char_heap)
            heapq.heappush(index_heap, (-i, char))

        while index_heap:
            _, char = heapq.heappop(index_heap)
            result += char
        
        return result

