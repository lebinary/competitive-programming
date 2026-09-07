/*
 * 408. Valid Word Abbreviation
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.2 MB (beats 11.5%)
 * Submitted: 2026-03-10 09:45:09 UTC
 * URL: https://leetcode.com/submissions/detail/1943783955/
 */

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), m = abbr.size();
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(isdigit(abbr[j])) {
                if(abbr[j] == '0') return false;
                string num = "";
                while(isdigit(abbr[j])) {
                    num += abbr[j];
                    j++;
                }
                i += stoi(num);
            } else {
                if(word[i] != abbr[j]) return false;
                i++;
                j++;
            }
        }

        return i == n && j == m;
    }
};

/**
# Clarifying:
- 2 properties: non-adjacent, non-empty
- cant start with zero OR be zero
- need to be 1 number, ie: 55 cannot mean 5+5

# Ideas: scan through both
- if abbr[j] is digit:
    - check edge cases
    - iterate j++ to get the num
    - i += num
- else:
    - check word[i] == abbr[j]

return i == word.size && j == abbr.size
**/
