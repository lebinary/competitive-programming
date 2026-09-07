/*
 * 14. Longest Common Prefix
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 96 ms (beats 6.4%)
 * Memory: 25.4 MB (beats 100.0%)
 * Submitted: 2021-08-18 16:00:39 UTC
 * URL: https://leetcode.com/submissions/detail/540475998/
 */

public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if(strs.Length < 1 || strs.Length > 200) {
            return "";
        }
        
        int charIndex = 0;
        string prefix = "";
        
        while(charIndex <= 200){
            if(charIndex >= strs[0].Length) {
                return prefix;
            }
            for(int i = 1; i < strs.Length; i++){
                if(charIndex >= strs[i].Length){
                    return prefix;
                }
                if(strs[0][charIndex] != strs[i][charIndex]){
                    return prefix;
                }
            }
            prefix += strs[0][charIndex];
            charIndex += 1;
        }
        return prefix;
    }
}
