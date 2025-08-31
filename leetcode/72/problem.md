## 72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

**Example 1:**
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

**Example 2:**
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

**Constraints:**
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

**Thoughts:**
- At any position i for word1 and j for word2, there are 2 cases:
  - word1[i] == word2[j]: skip, increase both i and j
  - word1[i] != word2[j]:
    - insert word2[j] in word1, increase j
    - remove word1[i], increase i
    - replace word1[i] with word2[j], increase both i, j
  - i reach end of word1:
    - insert word2[j]
  - j reach end of word2:
    - remove word1[i]
- Base case: if both i and j reach end, return 0.
