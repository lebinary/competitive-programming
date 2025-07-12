## 678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '\*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'\*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

**Example 1:**
Input: s = "()"
Output: true

**Example 2:**
Input: s = "(\*)"
Output: true

**Example 3:**
Input: s = "(\*))"
Output: true

**Constraints:**
1 <= s.length <= 100
s[i] is '(', ')' or '\*'.

**Thoughts:**
- Small constraint => bruteforce is possible
- Can't use stack, because we simply dont know what to do with `*` without exploring all the possibilities
- A different approach:
  - use 2 stacks, one to store the `index` of '(', one to store `index` of '*'
  - whenever encounter ')', prioritize removing '(' first, then '*'
  - after the first pass, do a second loop: remove all pair of index in stack1 and stack2 that satisfy this condition: `index` of '(' < `index` of '*'
  - if after both loops, stack1 is empty, then we done
