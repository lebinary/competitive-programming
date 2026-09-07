/*
 * 58. Length of Last Word
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 76 ms (beats 3.4%)
 * Memory: 22.7 MB (beats 100.0%)
 * Submitted: 2021-09-07 13:35:34 UTC
 * URL: https://leetcode.com/submissions/detail/550948979/
 */

public class Solution {
    public int LengthOfLastWord(string s) {
        int charCount = 0;
        for(int i = s.Length - 1; i >= 0; i--){
            if(s[i] != ' '){
                charCount++;
            }else{
                if(charCount > 0){
                    break;
                }
            }
        }
        return charCount;
    }
}
