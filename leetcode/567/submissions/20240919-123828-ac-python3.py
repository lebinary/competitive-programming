# 567. Permutation in String
# Difficulty: Medium
# Status: Accepted
# Runtime: 65 ms (beats 21.9%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-19 12:38:28 UTC
# URL: https://leetcode.com/submissions/detail/1395407284/

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # edge case
        if len(s1) > len(s2): return False

        # stores both initial hashmap
        count1 = [0] * 26
        count2 = [0] * 26

        for i in range(len(s1)):
            count1[ord(s1[i]) - ord('a')] += 1
            count2[ord(s2[i]) - ord('a')] += 1

        # get initial "matches"
        matches = 0
        for i in range(26):
            if count1[i] == count2[i]:
                matches += 1
        
        if matches == 26: return True # check if we lucky

        # slide window, update "matches", check if "matches" == 26
        for r in range(len(s1), len(s2)):
            l = r - len(s1)

            r_idx = ord(s2[r]) - ord('a') 
            count2[r_idx] += 1
            if count2[r_idx] == count1[r_idx]:
                matches += 1
            elif count2[r_idx] == count1[r_idx] + 1:
                matches -= 1
            r += 1

            l_idx = ord(s2[l]) - ord('a') 
            count2[l_idx] -= 1
            if count2[l_idx] == count1[l_idx]:
                matches += 1
            elif count2[l_idx] == count1[l_idx] - 1:
                matches -= 1
            l += 1

            if matches == 26: return True
        
        return False
