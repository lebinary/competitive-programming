/*
 * 133. Clone Graph
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 35.3%)
 * Memory: 12.3 MB (beats 29.4%)
 * Submitted: 2026-01-22 09:03:59 UTC
 * URL: https://leetcode.com/submissions/detail/1893074728/
 */


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
