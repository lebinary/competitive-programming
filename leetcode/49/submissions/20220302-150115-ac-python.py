# 49. Group Anagrams
# Difficulty: Medium
# Status: Accepted
# Runtime: 126 ms (beats 5.0%)
# Memory: 19.5 MB (beats 5.4%)
# Submitted: 2022-03-02 15:01:15 UTC
# URL: https://leetcode.com/submissions/detail/651965836/

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = defaultdict(list)
    
        for s in strs:
            count = [0] * 26

            for c in s:
                count[ord(c) - ord("a")] += 1

            res[tuple(count)].append(s)

        return res.values()
        
