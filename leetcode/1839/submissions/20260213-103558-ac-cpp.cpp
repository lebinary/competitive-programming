/*
 * 1839. Longest Substring Of All Vowels in Order
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 27 ms (beats 25.6%)
 * Memory: 29.4 MB (beats 44.1%)
 * Submitted: 2026-02-13 10:35:58 UTC
 * URL: https://leetcode.com/submissions/detail/1917902847/
 */

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size(), best = 0;
        int l = 0;
        
        for(int r = 0; r < n; ++r) {
            if(!valid(word, r)) l = r;
            if(word[l] == 'a' && word[r] == 'u') {
                best = max(best, r - l + 1);
            }
        }

        return best;
    };

    bool valid(string &word, int i) {
        if(i == 0) return word[i] == 'a';
        if(word[i] == 'a') return word[i-1] == 'a';
        if(word[i] == 'e') return word[i-1] == 'e' || word[i-1] == 'a'; 
        if(word[i] == 'i') return word[i-1] == 'i' || word[i-1] == 'e'; 
        if(word[i] == 'o') return word[i-1] == 'o' || word[i-1] == 'i'; 
        if(word[i] == 'u') return word[i-1] == 'u' || word[i-1] == 'o';
        return false;
    }
};
