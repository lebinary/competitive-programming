/*
 * 92. Reverse Linked List II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.3 MB (beats 38.9%)
 * Submitted: 2025-05-06 13:16:42 UTC
 * URL: https://leetcode.com/submissions/detail/1627001463/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prevL = dummy;
        ListNode* l = head;

        for(int i = 1; i < left; i++) {
            prevL = l;
            l = l->next;
        }
        ListNode* r = l;
        ListNode* postR = r? r->next : nullptr;
        for(int i = left; i < right; i++) {
            r = postR;
            postR = postR->next;
        }
        
        prevL->next = r;

        // reverse
        ListNode* prev = postR;
        ListNode* curr = l;
        while(curr != postR) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return dummy->next;
    }
};
