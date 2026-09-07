/*
 * 2062. Count Vowel Substrings of a String
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.5 MB (beats 69.5%)
 * Submitted: 2026-02-15 09:36:31 UTC
 * URL: https://leetcode.com/submissions/detail/1919918755/
 */

class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size(), res = 0;
        unordered_map<char, int> freqMin, freqMax;
        int lmin = 0, lmax = 0;

        for(int r = 0; r < n; ++r) {
            freqMax[word[r]]++;
            freqMin[word[r]]++;

            while(lmax <= r && freqMax.size() >= 5) {
                freqMax[word[lmax]]--;
                if(freqMax[word[lmax]] == 0) freqMax.erase(word[lmax]);
                lmax++;
            }

            while(lmin <= r && freqMin.size() > 5) {
                freqMin[word[lmin]]--;
                if(freqMin[word[lmin]] == 0) freqMin.erase(word[lmin]);
                lmin++;
            }

            if(!valid(freqMax) && valid(freqMin)) res += lmax - lmin;
        }

        return res;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool valid(unordered_map<char, int> &map) {
        if(map.size() != 5) return false;
        for(auto [k, v] : map) {
            if(!isVowel(k)) return false;
        }
        return true;
    }
};
