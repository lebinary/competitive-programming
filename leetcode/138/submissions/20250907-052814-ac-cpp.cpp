/*
 * 138. Copy List with Random Pointer
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 91.1%)
 * Memory: 15.2 MB (beats 29.1%)
 * Submitted: 2025-09-07 05:28:14 UTC
 * URL: https://leetcode.com/submissions/detail/1762273176/
 */

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> map;

        // phase 1: create new nodes
        Node *curr = head;
        while (curr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // phase 2: linking
        curr = head;
        while (curr) {
            if (curr->next) map[curr]->next = map[curr->next];
            if (curr->random) map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};
