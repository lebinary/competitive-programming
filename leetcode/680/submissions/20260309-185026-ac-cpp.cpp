/*
 * 680. Valid Palindrome II
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.2 MB (beats 55.7%)
 * Submitted: 2026-03-09 18:50:26 UTC
 * URL: https://leetcode.com/submissions/detail/1943228172/
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            if(s[r] == s[l]) {
                r--; l++; continue;
            }
            break;
        }

        if(r - l + 1 <= 2) return true;
        bool res = true;
        
        int l1 = l + 1, r1 = r;
        while(l1 < r1) {
            if(s[l1] == s[r1]) {
                r1--; l1++; continue;
            }

            res = false; break;
        }

        if(res == true) return res;

        res = true;
        l1 = l, r1 = r - 1;
        while(l1 < r1) {
            if(s[l1] == s[r1]) {
                r1--; l1++; continue;
            }
            res = false; break;
        }

        return res;
    }
};

/**
There are 2 paths to take once encounter the first diff:
- s[l] != s[r] && s[l+1] == s[r] => l++
- s[l] != s[r] && s[l] == s[r-] => r--

will need to check both path


"cu....cu"
**/
