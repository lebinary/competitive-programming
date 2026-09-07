# 76. Minimum Window Substring
# Difficulty: Hard
# Status: Accepted
# Runtime: 114 ms (beats 37.3%)
# Memory: 17.3 MB (beats 100.0%)
# Submitted: 2024-09-24 11:27:33 UTC
# URL: https://leetcode.com/submissions/detail/1400629288/

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""

        countT = Counter(t)
        window = {}

        have, need = 0, len(countT)
        res, resLen = [-1, -1], float("infinity")
        l = 0
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)

            if c in countT and window[c] == countT[c]:
                have += 1

            while have == need:
                # update our result
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1
                # pop from the left of our window
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        l, r = res
        return s[l : r + 1] if resLen != float("infinity") else ""






        
