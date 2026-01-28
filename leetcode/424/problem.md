# 424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

## Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

## Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

## Constraints:
1 <= s.length <= 10^5
s consists of only uppercase English letters.
0 <= k <= s.length

## Thoughts:
- A "valid" substr is s.t.: substr's len - max frequency char's count <= k
- substr's len can be derived from `l` and `r`
- substr's max frequency char's count can be derived from a freqMap
- Approach: sliding window
  shrink first to make sure the substr is valid
  compare with res

- Appoach 2: lazy sliding window
  Intuition: Given any window size, and "highest frequency count"
    - If we can fits the frequency in this window, (r-l+1 - maxFreq) <= k: then continue expansion
    - If cannot fits the frequency in this window, (r-l+1 - maxFreq) > k: slide the window forward (keeping the same size)
  By the end, n - l will be the best window size achievable
