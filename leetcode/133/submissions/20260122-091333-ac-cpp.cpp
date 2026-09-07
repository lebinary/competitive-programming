/*
 * 133. Clone Graph
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 35.3%)
 * Memory: 12.2 MB (beats 49.6%)
 * Submitted: 2026-01-22 09:13:34 UTC
 * URL: https://leetcode.com/submissions/detail/1893083051/
 */


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

