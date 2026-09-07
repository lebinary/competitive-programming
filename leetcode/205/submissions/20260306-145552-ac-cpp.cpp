/*
 * 205. Isomorphic Strings
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 4 ms (beats 22.9%)
 * Memory: 9.4 MB (beats 58.0%)
 * Submitted: 2026-03-06 14:55:52 UTC
 * URL: https://leetcode.com/submissions/detail/1939932036/
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
        
        for(int i = 0; i < n; ++i) {
            if(!mapS.count(s[i])) mapS[s[i]] = t[i];
            else if(mapS[s[i]] != t[i]) return false;

            if(!mapT.count(t[i])) mapT[t[i]] = s[i];
            else if(mapT[t[i]] != s[i]) return false;
        }

        return true;
    }
};

/**
good case:
s = "abb", t = "cdd"

bad case:
s = "abb", t = "cde"

Problem: detect one-to-many mapping
Algo:
Scan left -> right:
    if map[s[i]] empty:
        map[s[i]] = t[i]
    else if map[s[i]] != t[i]: return false

    do the same in the opposite direction
return true
**/
