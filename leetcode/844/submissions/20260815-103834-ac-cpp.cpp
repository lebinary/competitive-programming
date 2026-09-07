/*
 * 844. Backspace String Compare
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.5 MB (beats 68.7%)
 * Submitted: 2026-08-15 10:38:35 UTC
 * URL: https://leetcode.com/submissions/detail/2107533709/
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '#') {
                int j = i;
                while(j >= 0 && !isalpha(s[j])) j--;
                if(j >= 0 && isalpha(s[j])) s[j] = '-';
            }
        }

        for(int i = 0; i < t.size(); ++i) {
            if(t[i] == '#') {
                int j = i;
                while(j >= 0 && !isalpha(t[j])) j--;
                if(j >= 0 && isalpha(t[j])) t[j] = '-';
            }
        }

        int j = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                while(j < t.size() && !isalpha(t[j])) j++;
                if(j >= t.size() || s[i] != t[j]) return false;
                j++;
            }
        }
        while(j < t.size()) {
            if(isalpha(t[j])) return false;
            j++;
        }
 
        return true;
    }
};
