/*
 * 143. Reorder List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 22.9 MB (beats 26.1%)
 * Submitted: 2025-08-16 10:57:35 UTC
 * URL: https://leetcode.com/submissions/detail/1737165170/
 */

class Solution {
  public:
    void reorderList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode *curr0 = head;
        ListNode *curr1 = prev;
        while (curr0 && curr1) {
            ListNode *tmp0 = curr0->next;
            ListNode *tmp1 = curr1->next;

            curr0->next = curr1;
            curr1->next = tmp0;

            curr0 = tmp0;
            curr1 = tmp1;
        }
    }
};
