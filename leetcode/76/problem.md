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
- Sliding window approach
  - create a frequency map for `tCount`. init a frequency map for the window from [0, t.size() - 1], call `sCount`
  - calculate initial `matches` in `tCount` and `sCount`
  - start sliding window from t.size() -> s.size():
    - udpate `sCout` freq, if sCount[s[r]] == tCount[s[r]] => increment `matches`
    - if at some point `matches` == t.size(): capture a snapshot of the substr.
      - shrink the window, keep shrinking if (`matches` < t.size() || s[l] not in `tCount`)
