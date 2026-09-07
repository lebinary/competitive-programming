/*
 * 9. Palindrome Number
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 60 ms (beats 5.0%)
 * Memory: 16.4 MB (beats 100.0%)
 * Submitted: 2021-08-16 05:19:12 UTC
 * URL: https://leetcode.com/submissions/detail/539222756/
 */

public class Solution {
    public bool IsPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        int pop;
        while(x > revertedNumber) {
            pop = x % 10;
            revertedNumber = revertedNumber * 10 + pop;
            x /= 10;
        }
        
        return x == revertedNumber || x == revertedNumber / 10;
    }
}
