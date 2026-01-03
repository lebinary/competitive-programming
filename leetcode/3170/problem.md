# 3170. Lexicographically Minimum String After Removing Stars
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

## Example 1:
Input: s = "aaba*"
Output: "aab"
Explanation:
We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

## Example 2:
Input: s = "abc"
Output: "abc"
Explanation:
There is no '*' in the string.

## Constraints:
1 <= s.length <= 10^5
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.

## Thoughts:
- Once see a '*', need to have a list of smallest character
- Why delete a at index 3 but not index 1?
  Compare 'aab' and 'aba', because 'aab' < 'aba'
- Do we always want to delete the "rightmost", "smallest" character?
  Consider this example: 'aababa*'
  if delete rightmost => 'aabab'
  if delete second rightmost => 'aabba'
  => Yes, **delete rightmost**

- What if there are more than one `*`, i.e 'aaba*aca*'
  priorty left -> right or vice versa?
  - Left -> right:
    resulted in 'aabaca*' -> 'aabac'
  - Right -> left:
    resulted in 'aaba*ac' -> 'aabac'

- Another example: abcabc*abcabc*
  Best result: abcbcabcbc

- **Pseudo:**
  Need a heap to track the non-star, smallest character, ie. (a, -1) => smallest char, rightmost index
  Need a list of size n, of 0 and 1 value, indicate deletion

  for char : string:
    if non star: push to the min heap
    if star:
      [char, -index] = heap.top()
      res[index] = 1
      res[i] == 1

  build the result string
