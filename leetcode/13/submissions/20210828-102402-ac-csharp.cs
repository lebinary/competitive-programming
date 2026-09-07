/*
 * 13. Roman to Integer
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 143 ms (beats 5.0%)
 * Memory: 26.2 MB (beats 100.0%)
 * Submitted: 2021-08-28 10:24:02 UTC
 * URL: https://leetcode.com/submissions/detail/545536955/
 */

public class Solution {
    public int RomanToInt(string s) {
        int result = 0;
        Dictionary<char, int> romanInt = new Dictionary<char, int>();
        romanInt.Add('I', 1);
        romanInt.Add('V', 5);
        romanInt.Add('X', 10);
        romanInt.Add('L', 50);
        romanInt.Add('C', 100);
        romanInt.Add('D', 500);
        romanInt.Add('M', 1000);
        for(int i = 0; i < s.Length; i++){
            if(i > 0 && romanInt[s[i]] > romanInt[s[i-1]]){
                result += (romanInt[s[i]] - 2*romanInt[s[i-1]]);
            }else {
                result += romanInt[s[i]];
            }
        }
        return result;
    }
}
