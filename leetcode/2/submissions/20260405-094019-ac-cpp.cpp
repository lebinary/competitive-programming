/*
 * 2. Add Two Numbers
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 77 MB (beats 75.8%)
 * Submitted: 2026-04-05 09:40:20 UTC
 * URL: https://leetcode.com/submissions/detail/1969490509/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* node1 = l1;
        ListNode* node2 = l2;

        int carry = 0;
        while(node1 || node2) {
            int val = carry;
            if(node1) val += node1->val;
            if(node2) val += node2->val;
            carry = val / 10;

            ListNode* niw = new ListNode(val % 10);
            curr->next = niw;
            curr = curr->next;

            if(node1) node1 = node1->next;
            if(node2) node2 = node2->next;
        }

        if(carry) {
            ListNode* niw = new ListNode(carry);
            curr->next = niw;
            curr = curr->next;
        }

        return dummy->next;
    }
};
