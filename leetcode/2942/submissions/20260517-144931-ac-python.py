# 2942. Find Words Containing Character
# Difficulty: Easy
# Status: Accepted
# Runtime: 4 ms (beats 25.1%)
# Memory: 12.5 MB (beats 23.9%)
# Submitted: 2026-05-17 14:49:31 UTC
# URL: https://leetcode.com/submissions/detail/2005627772/

class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """
        res = []
        for i, word in enumerate(words):
            if x in word:
                res.append(i)
        return res
        
