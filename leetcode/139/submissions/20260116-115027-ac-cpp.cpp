/*
 * 139. Word Break
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.3 MB (beats 59.8%)
 * Submitted: 2026-01-16 11:50:27 UTC
 * URL: https://leetcode.com/submissions/detail/1886755415/
 */

class TrieNode {
  public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
};

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        TrieNode *root = new TrieNode();

        for (string &word : wordDict) {
            TrieNode *node = root;
            for (char c : word) {
                if (node->children.count(c) == 0) node->children[c] = new TrieNode();
                node = node->children[c];
            };
            node->isEnd = true;
        };

        vector<int> dp(s.size(), -1);
        return dfs(s, dp, root, 0);
    }

    bool dfs(string &s, vector<int> &dp, TrieNode *root, int start) {
        if (start >= s.size()) return true;
        if (dp[start] != -1) return dp[start];

        TrieNode *node = root;
        for (int end = start; end < s.size(); end++) {
            if (node->children.count(s[end]) == 0) break;
            node = node->children[s[end]];

            if (node->isEnd) {
                if (dfs(s, dp, root, end + 1)) {
                    return dp[start] = true;
                }
            }
        }

        return dp[start] = false;
    }
};
