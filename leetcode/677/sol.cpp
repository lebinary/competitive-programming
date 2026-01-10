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
    int val;
    unordered_map<char, TrieNode *> children;
    TrieNode() : isEnd(false), val(0) {}
};

class MapSum {
  public:
    TrieNode *root;
    MapSum() { this->root = new TrieNode(); }

    void insert(string key, int val) {
        TrieNode *node = root;
        for (char c : key) {
            if (node->children.count(c) == 0) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
        node->val = val;
    }

    int sum(string prefix) {
        TrieNode *node = root;
        return dfs(node, prefix, 0);
    }

    int dfs(TrieNode *node, string &prefix, int i) {
        if (node == nullptr) return 0;

        if (i < prefix.size()) {
            if (node->children.count(prefix[i]) == 0) return 0;
            return dfs(node->children[prefix[i]], prefix, i + 1);
        }

        int tot = node->val;
        for (auto &[c, child] : node->children) {
            tot += dfs(child, prefix, i);
        }

        return tot;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
