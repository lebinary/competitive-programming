/*
 * 211. Design Add and Search Words Data Structure
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 673 ms (beats 19.3%)
 * Memory: 548.2 MB (beats 87.7%)
 * Submitted: 2025-07-16 12:28:45 UTC
 * URL: https://leetcode.com/submissions/detail/1700039555/
 */


class TrieNode {
  public:
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    TrieNode() : isEnd(false) {}
};

class WordDictionary {
    TrieNode *root;

  public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(string word) {
        TrieNode *curr = root;

        for (char c : word) {
            if (curr->children.count(c) == 0) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(0, root, word); }

    bool dfs(int i, TrieNode *curr, string &word) {
        if (i >= word.size() && curr->isEnd) return true;

        if (word[i] == '.') {
            for (auto [_, trie] : curr->children) {
                if (dfs(i + 1, trie, word)) return true;
            }
        } else {
            if (curr->children.count(word[i])) {
                if (dfs(i + 1, curr->children[word[i]], word)) return true;
            };
        }

        return false;
    }
};
