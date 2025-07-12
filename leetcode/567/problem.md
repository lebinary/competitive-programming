## 567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

**Example 1:**
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

**Example 2:**
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

**Constraints:**
1 <= s1.length, s2.length <= 10^4
s1 and s2 consist of lowercase English letters.

**Thoughts**
- For each character in s2, there are 2 possibilities:
  - character belongs to s1,
    - "pluck" it out of s1, continue to next character.
  - character NOT belongs to s1:
    - return false, backtrack, re-insert the character back to s1.
- Success criteria:
  - s1 is empty, by the end
  => O(n^2)

- Sliding window approach:
  - Insight, use a window of size s1, and slide it on s2. Keeping 2 maps, for s1 and s2.
  - At some point while sliding on s2:
    - If we have 2 maps match perfectly, then we done.
    - Else continue to the end, and return false.
