/*
 * 25. Reverse Nodes in k-Group
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1 ms (beats 3.8%)
 * Memory: 16.5 MB (beats 70.2%)
 * Submitted: 2026-01-20 15:11:22 UTC
 * URL: https://leetcode.com/submissions/detail/1891140091/
 */

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *dummy2 = dummy;

        ListNode *start = head, *end = head;
        int count = 0;

        while (end != nullptr) {
            count++;
            end = end->next;

            if (count == k) {
                ListNode *prev = end, *curr = start;
                while (curr != end) {
                    ListNode *tmp = curr->next;
                    curr->next = prev;

                    prev = curr;
                    curr = tmp;
                }

                dummy2->next = prev;
                dummy2 = start;
                start = end;
                count = 0;
            }
        }

        return dummy->next;
    }
};
