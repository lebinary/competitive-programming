/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 8 ms (beats 81.5%)
 * Memory: 11.8 MB (beats 81.1%)
 * Submitted: 2025-05-05 13:52:09 UTC
 * URL: https://leetcode.com/submissions/detail/1626129996/
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        ListNode* turtle = head;
        ListNode* hare = head->next;

        while(hare) {
            if (turtle == hare) return true;

            if (hare->next) hare = hare->next->next;
            else hare = nullptr;
            
            turtle = turtle->next;
        }

        return false;
    }
};
