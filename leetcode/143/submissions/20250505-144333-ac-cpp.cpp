/*
 * 143. Reorder List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.9 MB (beats 26.1%)
 * Submitted: 2025-05-05 14:43:33 UTC
 * URL: https://leetcode.com/submissions/detail/1626169780/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // find head of second half
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // merge two halves
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr1 = head;
        ListNode* curr2 = prev;
        while(curr1 && curr2) {
            ListNode* nxt1 = curr1->next;
            ListNode* nxt2 = curr2->next;

            curr1->next = curr2;
            curr2->next = nxt1;

            curr1 = nxt1;
            curr2 = nxt2;
        }
    }
};
