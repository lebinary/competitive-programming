# 76. Minimum Window Substring
# Difficulty: Hard
# Status: Accepted
# Runtime: 93 ms (beats 63.0%)
# Memory: 14 MB (beats 68.9%)
# Submitted: 2023-12-22 14:54:53 UTC
# URL: https://leetcode.com/submissions/detail/1125931652/

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if t == "": return ""

        countT = {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        # have, need to store the frequency of a character. Ex: if s has 3 A's and t has 3 A's, "have" increment by 1 
        have = 0
        need = len(countT)
        res = [-1, -1]
        res_len = float('inf')
        
        window = {}
        l = 0
        r = 0
        while r < len(s):
            c = s[r]

            # expand window by push to the right
            window[c] = 1 + window.get(c, 0)
            if window.get(c) == countT.get(c):
                have += 1

            while have == need:
                curr_res_len = r - l + 1
                
                # update result
                if curr_res_len < res_len:
                    res = [l, r]
                    res_len = curr_res_len

                # shrink window by pop from the left
                window[s[l]] -= 1
                if window.get(s[l]) < countT.get(s[l]):
                    have -= 1
                l += 1
            r += 1
        
        l , r = res
        return s[l : r + 1] if res_len != float('inf') else ""  

            
