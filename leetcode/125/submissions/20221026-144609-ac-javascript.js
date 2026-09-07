/*
 * 125. Valid Palindrome
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 144 ms (beats 5.0%)
 * Memory: 45.3 MB (beats 100.0%)
 * Submitted: 2022-10-26 14:46:09 UTC
 * URL: https://leetcode.com/submissions/detail/830754959/
 */

/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let l = 0;
    let r = s.length-1;
    
    const alphaNumeric = /^[a-z0-9]+$/i;
    
    while(l < r){
        if(alphaNumeric.test(s[l]) && alphaNumeric.test(s[r])){
            if(s[l].toLowerCase() !== s[r].toLowerCase()) {
                return false;
            }
            l++;
            r--;
        }
        else if (!alphaNumeric.test(s[l])) {
            l++;
        }
        else {
            r--
        };
    }
    
    return true;
}
