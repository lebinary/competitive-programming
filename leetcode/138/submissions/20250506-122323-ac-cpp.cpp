/*
 * 138. Copy List with Random Pointer
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.2 MB (beats 29.1%)
 * Submitted: 2025-05-06 12:23:23 UTC
 * URL: https://leetcode.com/submissions/detail/1626967206/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hm;

        Node* curr = head;
        while(curr) {
            hm[curr] = new Node(curr->val);
            curr = curr->next;
        }

        Node* dummy = new Node(-1);
        dummy->next = hm[head];
        curr = head;
        while(curr) {
            Node* niw = hm[curr];

            niw->next = hm[curr->next];
            niw->random = hm[curr->random];

            curr = curr->next;
        }

        return dummy->next;
    }
};
