/*
 * 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 14.8 MB (beats 93.0%)
 * Submitted: 2025-05-06 11:28:08 UTC
 * URL: https://leetcode.com/submissions/detail/1626934001/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && n > 0) {
            curr = curr->next;
            n--;
        }

        while(curr) {
            prev = prev->next;
            curr = curr->next;
        }

        prev->next = prev->next->next;
        return dummy->next;
    }
};
