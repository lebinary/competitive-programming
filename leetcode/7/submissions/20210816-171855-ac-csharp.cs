/*
 * 7. Reverse Integer
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 44 ms (beats 5.7%)
 * Memory: 15.3 MB (beats 100.0%)
 * Submitted: 2021-08-16 17:18:55 UTC
 * URL: https://leetcode.com/submissions/detail/539469215/
 */

public class Solution {
    public int Reverse(int x) {
        int reversed = 0;
        int pop;
        int INT_MAX = Int32.MaxValue;
        int INT_MIN = Int32.MinValue;
        while (x != 0) {
            pop = x % 10;
            
            if (reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
            if (reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;
            reversed = reversed * 10 + pop;
            x /= 10;
        }
        
        return reversed;
    }
}
