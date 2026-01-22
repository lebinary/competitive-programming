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
    unordered_map<int, Node *> niw;
    Node *cloneGraph(Node *node) {
        if (node == nullptr) return nullptr;
        if (niw.count(node->val)) return niw[node->val];

        niw[node->val] = new Node(node->val);

        for (Node *nei : node->neighbors) {
            niw[node->val]->neighbors.push_back(cloneGraph(nei));
        }

        return niw[node->val];
    }
};
