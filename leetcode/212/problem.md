## 212. Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

**Example 1:**
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

**Example 2:**
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

**Constraints:**
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

**Thoughts:**
- Bruteforce approach: for each word, find if it exist on the board => O(words.length * m * n * word[i].length) = (3*10^4) * 12 * 12 * 10 = (3 * 10^7) => TLE
- Optimize: turn the matrix into a graph, i.e [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
  => {
      "a-[r]-[c]": ["a-[r]-[c]", "o-[r]-[c]"],
      "o-[r]-[c]": ["a-[r]-[c]", "e-[r]-[c]", "t-[r]-[c]"],
      ...
    }

    {
      "o": ["o-[r]-[c]"]
      "a": ["a-[r]-[c]", "a-[r]-[c]"]
      ...
    }

  => Runtime: O(m * n) + O(words.length * word[i].length)

- Best solution: Use tries (prefix tree) to store the words.
  For each cell in board, check if any word in prefix tree "matches", if yes, add in result
  => Time complexity: O(m * n * log(word[i].length)) = 12 * 12 * 10 = 10^3
    Space complexity: O(uniq charaters in words + (m * n))
