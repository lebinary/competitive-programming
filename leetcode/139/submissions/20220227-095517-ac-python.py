# 139. Word Break
# Difficulty: Medium
# Status: Accepted
# Runtime: 29 ms (beats 6.0%)
# Memory: 13.2 MB (beats 5.9%)
# Submitted: 2022-02-27 09:55:17 UTC
# URL: https://leetcode.com/submissions/detail/649838028/

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp = [False] * (len(s) + 1)
        
        dp[len(s)] = True
        
        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                if (i + len(w)) <= len(s) and s[i: i+len(w)] == w:
                    dp[i] = dp[i+len(w)]
                if dp[i]:
                    break
                
        return dp[0]
