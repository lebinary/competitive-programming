# 1915. Number of Wonderful Substrings
A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

## Example 1:
Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"

## Example 2:
Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"

## Example 3:
Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"

## Constraints:
1 <= word.length <= 10^5
word consists of lowercase English letters from 'a' to 'j'.

## Thoughts:
- "wonderful" <=> All letters are even count OR only one letter can be odd
  - all even <=> count % 2 == 0
  - at most one odd <=> all even except 1

- sum[i...j] % 2 = 0 <=> (prefix[j] - prefix[i-1]) % 2 = 0
- prefix[j] % 2 = prefix[i-1] % 2 across 25 characters
- Since values on LHS and RHS in range [0,1] => convert to save parity only:
  parity[j] - parity[i-1] = 0
  abs(parity[J] - parity[I - 1]) = [000..1000] vector with only 1 element equal 1
  => parity[J] - abs([000.1..0]) = parity[i-1]

- Rephrase the problem as: Count all pair {i,j} s.t. parity[j] ~= parity[i-1], "~" because we allow up to 1 element from vector j and i to be different

- Pseudo:
  parity(26, 0)

  for(char c : word):
    parity[c - 'a'] ^= 1;

  for(i = 0; i < n; ++i):
    if(map.containsKey(parity[i]) res += map[parity[i]]
    for j in range(26):
      err = [0,0,0...]
      err[j] = 1
      if(map.containsKey(parity[i] - err)) res += map[parity[i] - err]
      if(map.containsKey(parity[i] + err)) res += map[parity[i] + err]
    map[parity[i]]++



"" , parity=[0...0], res=0
"a", parity=[1...0], res=1
"ab", parity=[11..0], res=2
"aba", parity=[11..0], res=
