/*
 * 1650. Lowest Common Ancestor of a Binary Tree III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 36.2%)
 * Memory: 15.6 MB (beats 23.5%)
 * Submitted: 2026-03-14 19:21:17 UTC
 * URL: https://leetcode.com/submissions/detail/1948349943/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* curr = p;
        unordered_set<Node*> path;

        while(curr) {
            if(curr == q) return curr;
            path.insert(curr);
            curr = curr->parent;
        }

        curr = q;
        while(curr) {
            if(curr == p) return curr;
            if(path.count(curr)) return curr;
            curr = curr->parent;
        }

        return nullptr;
    }
};

/**
There are 2 cases:
- p is child of q or vice versa
- p and q are in different subtree

# Approach: 
- Traverse p up, check if q is in its path: return 
- Traverse q up, check if p is in its path: return
- Check where pathP and pathQ intersect: return
return None
**/
