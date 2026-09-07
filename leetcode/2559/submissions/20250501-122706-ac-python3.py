# 2559. Count Vowel Strings in Ranges
# Difficulty: Medium
# Status: Accepted
# Runtime: 15 ms (beats 93.8%)
# Memory: 49.6 MB (beats 7.9%)
# Submitted: 2025-05-01 12:27:07 UTC
# URL: https://leetcode.com/submissions/detail/1622769293/

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        prefix = [0]

        count = 0
        for word in words:
            if word[0] in vowels and word[-1] in vowels:
                count += 1
            prefix.append(count)

        res = []
        for query in queries:
            l, r = query         
            res.append(prefix[r+1] - prefix[l])
        
        return res

            
