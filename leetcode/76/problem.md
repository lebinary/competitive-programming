## 76. Minimum Window Substring

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

**Example 1:**
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

**Example 2:**
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

**Example 3:**
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

**Constraints:**
m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.

**Follow up:** Could you find an algorithm that runs in O(m + n) time?

**Thoughts:**
- Sliding window approach:
  Pseudo:
  var match = 52, sFreq, tFreq

  for each char in t:
    increment tFreq[char]
    check if crossed to the bad side: match--

  l = 0
  for each char in s:
    increament sFreq[char]
    check if crossed to the good side: match++

    while(good):
      update res
      decrement sFreq[charLeft]
      check if crossed to the bad side: match--
      shrink
  return res

- The sol2 approach inspired by this problem https://leetcode.com/problems/find-all-anagrams-in-a-string. The only differences here are:
  - Anagram (equality):
    Valid when sFreq[c] == tFreq[c] for all chars
    Expand: match++ when becoming equal, match-- when leaving equal (going over)
    Shrink: match++ when becoming equal (coming back from over), match-- when leaving equal (going under)

  - Min window (threshold):
    Valid when sFreq[c] >= tFreq[c] for all chars
    Expand: match++ when crossing threshold upward, that's it
    Shrink: match-- when crossing threshold downward, that's it
