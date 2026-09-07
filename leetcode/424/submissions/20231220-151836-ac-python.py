# 424. Longest Repeating Character Replacement
# Difficulty: Medium
# Status: Accepted
# Runtime: 104 ms (beats 94.7%)
# Memory: 13.7 MB (beats 81.1%)
# Submitted: 2023-12-20 15:18:36 UTC
# URL: https://leetcode.com/submissions/detail/1124336271/

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # TIP: Replace the lowest frequency characters and make sure the replacement count is under or equal k
        count = {}
        l = 0
        res = 1

        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)

            # Shrink the window whenever replaceables > k
            while (r - l + 1) - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)
        
        return res
