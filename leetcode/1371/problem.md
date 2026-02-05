# 1371. Find the Longest Substring Containing Vowels in Even Counts
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

## Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

## Example 2:
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

## Example 3:
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.

## Constraints:
1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.


## Thoughts:
- Sliding window? Cant, when shrink, might improve result of one vowel, but worsen another
- Prefix sum: consider just `1 vowel`
  s = "eleetneet"
  => prefix = [1,1,2,3,3,3,4,5,5]
  Problem: sum[i..j] % 2 == 0
  <=> prefix[j] % 2 = prefix[i-1] % 2
  <=> parity[j] = parity[i-1] since k % 2 can only have values {0, 1} <COND. A>
  Rephrase problem: Find max(j - i + 1) s.t. satisfy <COND. A>

- Learning: xor % 2 is same as prefixSum
