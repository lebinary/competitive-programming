/*
 * 1650. Lowest Common Ancestor of a Binary Tree III
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 36.2%)
 * Memory: 14.1 MB (beats 75.8%)
 * Submitted: 2026-03-14 19:32:49 UTC
 * URL: https://leetcode.com/submissions/detail/1948357510/
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
        Node* currP = p;
        Node* currQ = q;

        while(currP != currQ) {
            currP = currP->parent ? currP->parent : q;
            currQ = currQ->parent ? currQ->parent : p;
        }

        return currP;
    }
};

/**
# Approach 2: Dont need a set
- Ideas: 
    - Let path from p -> root = a + c
    - Let path from q -> root = b + c, where c is distance from LCA -> root
    => Making both p and q traverse a distance of (a + b + c) will land in LCA
**/
