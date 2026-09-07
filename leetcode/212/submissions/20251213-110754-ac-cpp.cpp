/*
 * 212. Word Search II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1483 ms (beats 11.0%)
 * Memory: 20.4 MB (beats 21.6%)
 * Submitted: 2025-12-13 11:07:54 UTC
 * URL: https://leetcode.com/submissions/detail/1854441384/
 */

class TrieNode {
  public:
    unordered_map<char, TrieNode *> children;
    bool isWord;

    TrieNode() {
        children = {};
        isWord = false;
    }

    void addWord(string word) {
        TrieNode *cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
  public:
    int R, C, N;

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        this->R = board.size(), this->C = board[0].size(), this->N = words.size();
        vector<vector<bool>> seen = vector<vector<bool>>(R, vector<bool>(C, false));
        unordered_set<string> uniq_res;
        TrieNode *node = new TrieNode();

        for (string word : words) node->addWord(word);

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                dfs(board, seen, uniq_res, r, c, node, "");
            }
        }

        return vector<string>(uniq_res.begin(), uniq_res.end());
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &seen, unordered_set<string> &res, int r, int c, TrieNode *node, string word) {
        if (r < 0 || r >= R || c < 0 || c >= C || seen[r][c] || !node->children.count(board[r][c])) return;

        seen[r][c] = true;

        node = node->children[board[r][c]];
        word += board[r][c];

        if (node->isWord) res.insert(word);

        dfs(board, seen, res, r + 1, c, node, word);
        dfs(board, seen, res, r, c + 1, node, word);
        dfs(board, seen, res, r - 1, c, node, word);
        dfs(board, seen, res, r, c - 1, node, word);

        seen[r][c] = false;
    }
};
