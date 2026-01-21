# 5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

## Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

## Example 2:
Input: s = "cbbd"
Output: "bb"

## Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

## Thoughts:
- Greedy approach:
  For each character, consider it as the "middle point", and try to expand as far out to both sides as possible, there are 2 cases:
  - i is exactly in the middle
  - i & i+1 are the middle (only valid if s[i] == s[i+1] && i < n - 1)
- DP approach:
  2 inputs: l and r
  dp[n][n]
  best = ""
  dfs(l, r):
    l < r: return false
    l == r: return s[l] == s[r]
    l == r + 1: return s[l] == s[r + 1]
    if(s[l] == s[r] && s[l + 1][s - 1] && r - l + 1 > best.size()) best = s.substr(l, r - l + 1)

    dfs(l + 1, r)
    dfs(l, r - 1)
    dfs(l + 1, r - 1)

  dfs(0, n - 1)
  return best
