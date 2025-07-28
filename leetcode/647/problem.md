## Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

**Example 1:**
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

**Example 2:**
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

**Constraints:**
1 <= s.length <= 1000
s consists of lowercase English letters.

**Thoughts:**
- Relatively small constraint -> bruteforce maybe?
- Bruteforce approach:
  - For each `l`, `r` pair of indices, check if `s[l, r]` is a palindrome. => O(n^3)
- "Start from middle" approach:
  - For each character, "expand" both sides and count palindrome.
  - For each "gap", "expand" both sides and count palindrome.
  => O(n^2)
