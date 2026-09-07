/*
 * 844. Backspace String Compare
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.3 MB (beats 96.4%)
 * Submitted: 2026-08-15 12:25:38 UTC
 * URL: https://leetcode.com/submissions/detail/2107631316/
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSkip = 0, tSkip = 0;
        int i = s.size() - 1, j = t.size() - 1;
        
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    sSkip++; i--;
                } else if(sSkip > 0) {
                    sSkip--; i--;
                } else break;
            }

            while(j >= 0) {
                if(t[j] == '#') {
                    tSkip++; j--;
                } else if(tSkip > 0) {
                    tSkip--; j--;
                } else break;
            }

            if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if((i >= 0) != (j >= 0)) return false;

            i--; j--;
        }
        
        return true;
    }
};
