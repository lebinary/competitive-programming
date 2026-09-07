/*
 * 443. String Compression
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.7 MB (beats 76.8%)
 * Submitted: 2026-03-27 16:02:38 UTC
 * URL: https://leetcode.com/submissions/detail/1961033843/
 */

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0, j = 0;

        while(j < n) {
            int freq = 0;
            while(j + freq < n && chars[j] == chars[j + freq]) {
                freq++;
            }

            chars[i++] = chars[j];
            
            if(freq > 1) {
                string freqStr = to_string(freq);
                
                for(char c : freqStr) {
                    chars[i++] = c;
                }
            };

            j += freq;
        }

        return i;
    }
};

/**
- not sorted
- "a" -> "a"
- "aa" -> "a2"
- "aa...aa" -> "aN"
=> input.size >= output.size

# Approach: Sliding window

i = 0
- for r in chars:
    while chars[l] != chars[r]:
        l++
    if chars[l] == chars[r]:
        replaceChars(i)
return i


TC: O(n)
SC: O(26)
**/
