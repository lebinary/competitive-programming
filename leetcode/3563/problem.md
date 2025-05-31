## 3563. Lexicographically Smallest String After Adjacent Removals

You are given a string s consisting of lowercase English letters.

You can perform the following operation any number of times (including zero):

Remove any pair of adjacent characters in the string that are consecutive in the alphabet, in either order (e.g., 'a' and 'b', or 'b' and 'a').
Shift the remaining characters to the left to fill the gap.
Return the lexicographically smallest string that can be obtained after performing the operations optimally.

Note: Consider the alphabet as circular, thus 'a' and 'z' are consecutive.


**Thinking process**
Can we dvide and conquer this problem?
  - No, counter example:
    Input: s = "abccde"
    Output: "ab"

    But if divided and conquer in the middle, then:
      "abc" -> "a"
      "cde" -> "c"

      combine result give "ac", which is not "ab"

Therefore, need to bruteforce each character
