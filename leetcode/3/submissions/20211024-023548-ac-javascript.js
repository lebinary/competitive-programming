/*
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 100 ms (beats 20.4%)
 * Memory: 44.1 MB (beats 100.0%)
 * Submitted: 2021-10-24 02:35:48 UTC
 * URL: https://leetcode.com/submissions/detail/576147459/
 */

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let test = '';
  let res = -1;
  if (s.length <= 1) return s.length;

  for (let i = 0; i < s.length; i++) {
    let currentChar = s[i];
    if (test.includes(currentChar)) {
      test = test.slice(test.indexOf(currentChar) + 1);
    }
    test += currentChar;
    res = Math.max(test.length, res);
  }

  return res;
};
