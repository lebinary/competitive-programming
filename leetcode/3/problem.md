## 3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

**Example 1:**
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

**Example 2:**
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

**Example 3:**
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

**Constraints:**
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

**Thoughts:**
- Two pointers, right one keep increment
- If at any point sees a duplicate, shrink the left until the duplicate is gone
- Record the length
