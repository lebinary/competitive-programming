# 115. Distinct Subsequences
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

## Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

## Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

## Constraints:
1 <= s.length, t.length <= 1000
s and t consist of English letters.

## Thoughts:
- Let i be index of `s` and j be index of `t`, assume s.size >= t.size
- Basecase:
  if j >= t.size: return 1
  if i >= s.size: return 0
- Body: for any i, j
  - if(s[i] == t[j]) take: dfs(i + 1, j + 1)
  - skip; dfs(i + 1, j)
  return sum of 2 branch
- Time: O(2^n) without memoization and O(n * m) with memoization, where n = s.size, m = t.size
- Space: O(n) for the recursion stack without memo, O(nxm) for `dp` matrix with memo
