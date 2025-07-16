#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
