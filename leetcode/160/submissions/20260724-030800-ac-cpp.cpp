/*
 * 160. Intersection of Two Linked Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 70 ms (beats 18.5%)
 * Memory: 28.8 MB (beats 12.8%)
 * Submitted: 2026-07-24 03:08:00 UTC
 * URL: https://leetcode.com/submissions/detail/2079001809/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;
        ListNode* curr = headA;
        while(curr) {
            seen.insert(curr);
            curr = curr->next;
        }
        curr = headB;
        while(curr) {
            if(seen.count(curr)) return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};
