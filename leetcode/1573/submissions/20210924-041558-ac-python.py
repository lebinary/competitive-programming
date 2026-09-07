# 1573. Number of Ways to Split a String
# Difficulty: Medium
# Status: Accepted
# Runtime: 144 ms (beats 10.0%)
# Memory: 17.1 MB (beats 15.0%)
# Submitted: 2021-09-24 04:15:58 UTC
# URL: https://leetcode.com/submissions/detail/560077491/

class Solution(object):
    def numWays(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD =  10**9 + 7
        if len(s) < 3: return 0
        
        total_one_count = s.count('1')
        
        if total_one_count == 0: return ((len(s)-1)*(len(s)-2)/2)%MOD
        
        if total_one_count % 3 == 0:
            partial_one_count = total_one_count / 3
            
            one_count = 0
            gaps_count = 0
            gaps = []
            for i in range(len(s)):
                if s[i] == '1':
                    if one_count == partial_one_count:
                        one_count = 1
                        gaps_count += 1
                        gaps.append(gaps_count)
                        if len(gaps) < 2:
                            gaps_count = 0
                            continue
                        else: break
                    one_count += 1
                if s[i] == '0':
                    if one_count == partial_one_count:
                        gaps_count += 1
            return gaps[0] * gaps[1] %MOD
        else: return 0
