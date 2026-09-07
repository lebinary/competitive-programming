# 49. Group Anagrams
# Difficulty: Medium
# Status: Accepted
# Runtime: 98 ms (beats 5.0%)
# Memory: 17.1 MB (beats 21.9%)
# Submitted: 2023-10-17 13:14:37 UTC
# URL: https://leetcode.com/submissions/detail/1077526224/

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        hm = {}
        for str in strs:
            key = ''.join(sorted(str))
            if hm.get(key):
                hm[key].append(str)
            else:
                hm[key] = [str]
        
        print(hm)
        return hm.values()


        
