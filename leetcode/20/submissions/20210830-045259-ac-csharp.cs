/*
 * 20. Valid Parentheses
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 172 ms (beats 5.1%)
 * Memory: 22.3 MB (beats 100.0%)
 * Submitted: 2021-08-30 04:52:59 UTC
 * URL: https://leetcode.com/submissions/detail/546484407/
 */

public class Solution {
    public bool IsValid(string s) {
        if(s.Length % 2 != 0){
            return false;
        }
        
        Stack<char> parentheses = new Stack<char>();
        
        for(int i = 0; i < s.Length; i++){            
            // If open brackets then push in stack
            if(s[i] == '('){
                parentheses.Push(')');
            }else if( s[i] == '{') {
                parentheses.Push('}');
            }else if( s[i] == '[') {
                parentheses.Push(']');
            }
            
            //If close brackets
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(parentheses.Count == 0){
                    return false;
                }
                if (s[i] != parentheses.Pop()) {
                    return false;
                }
            }
        }
        
        if(parentheses.Count == 0){
            return true;
        }else return false;
    }
}
