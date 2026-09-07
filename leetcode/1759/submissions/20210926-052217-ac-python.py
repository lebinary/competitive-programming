# 1759. Count Number of Homogenous Substrings
# Difficulty: Medium
# Status: Accepted
# Runtime: 164 ms (beats 5.3%)
# Memory: 17.5 MB (beats 21.1%)
# Submitted: 2021-09-26 05:22:17 UTC
# URL: https://leetcode.com/submissions/detail/561122392/

"""
Because:
a    => a: 1
aa   => a: 2, aa: 1
aaa  => a: 3, aa: 2, aaa: 1
aaaa => a: 4, aa: 3, aaa: 2, aaaa: 1

We can see new count = new char count + old count
Example: new 'aaa' count = new 'a' count + old ('a' count and 'aa' count)
<=>      new 'aaa' count = 3             + (2 + 1) 
"""

class Solution(object):
    def countHomogenous(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9 + 7
        count = 1
        res = 1
        
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                count += 1
            else:
                count = 1
            res += count
                
        
        return res % MOD
        
        
        
        
