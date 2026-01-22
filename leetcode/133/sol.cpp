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

// Definition for a Node.
class Node {
  public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;

        unordered_map<int, Node *> niw;
        unordered_set<int> visited;
        build(node, niw, visited);
        return niw[1];
    }

    void build(Node *node, unordered_map<int, Node *> &niw, unordered_set<int> &visited) {
        if (node == nullptr || visited.count(node->val)) return;

        visited.insert(node->val);

        niw[node->val] = niw[node->val] != nullptr ? niw[node->val] : new Node(node->val);

        for (Node *nei : node->neighbors) {
            niw[nei->val] = niw[nei->val] != nullptr ? niw[nei->val] : new Node(nei->val);
            niw[node->val]->neighbors.push_back(niw[nei->val]);

            build(nei, niw, visited);
        }
    }
};
