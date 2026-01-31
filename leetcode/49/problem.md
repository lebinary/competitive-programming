# 49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

## Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

## Example 2:
Input: strs = [""]
Output: [[""]]

## Example 3:
Input: strs = ["a"]
Output: [["a"]]

## Constraints:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

## Thoughts:
- For each word, build frequence array:
  - check if freuency array existed, if yes, push into that bucket
- Question: how to hash an array of frequencies?
  - Treat vector as coefficients, i.e vector=[a,b,c] => hash = 31^2a + 31b + c. Picks 31 because prime, fast to compute (`x * 31 = (x << 5) - x)`, compiler loves this)
  - For uint64 hash, the hash space is N = 2^64, expected collision after roughly sqrt(N) = 2^32 = 4 billions. Therefore, only with 4 billions unique values do we expect a collision, which is well above the contraints of `10^4`, so we dont have to worry about collision using this hash, in this problem.
- Time: O(n * m) , n = strs.size, m = strs[i].size
- Space: O(n * m)
