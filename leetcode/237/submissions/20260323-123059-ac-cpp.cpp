/*
 * 237. Delete Node in a Linked List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 10 ms (beats 34.9%)
 * Memory: 12.2 MB (beats 98.5%)
 * Submitted: 2026-03-23 12:30:59 UTC
 * URL: https://leetcode.com/submissions/detail/1956678439/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
    }
};
