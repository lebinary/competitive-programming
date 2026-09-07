/*
 * 708. Insert into a Sorted Circular Linked List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 5 ms (beats 64.2%)
 * Memory: 13.1 MB (beats 96.7%)
 * Submitted: 2026-03-26 11:40:51 UTC
 * URL: https://leetcode.com/submissions/detail/1959853506/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node* minNode = new Node(INT_MIN);
        Node* maxNode = new Node(INT_MAX);
    
        Node* node = head;
        int round = 0;
        while(node->val <= node->next->val && round < 2) {
            if(node == head) round++;
            node = node->next;
        }

        minNode->next = node->next;
        node->next = maxNode;

        node = minNode;
        while(node != maxNode) {
            if(node->val <= insertVal && insertVal <= node->next->val) {
                break;
            }
            node = node->next;
        }

        Node* newNode = new Node(insertVal, node->next);
        node->next = newNode;

        node = minNode;
        while(node->next != maxNode) node = node->next;
        node->next = minNode->next;

        return head;
    }
};

/**
# Analysis
Need to find the node where curr <= insertVal <= curr.next

# Approach
- First, need to identify the smallest and largest
    - Node(INT_MIN) -> smallest
    - largest -> Node(INT_MAX)
- Scan through: insert new Node in where curr <= insertVal <= curr.next
- Reconnect: 
    largest -> smallest
- Return head
    
**/
