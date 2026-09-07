/*
 * 160. Intersection of Two Linked Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 52 ms (beats 80.2%)
 * Memory: 24 MB (beats 55.6%)
 * Submitted: 2026-07-24 03:55:53 UTC
 * URL: https://leetcode.com/submissions/detail/2079033520/
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
        int lenA = 0, lenB = 0;
        ListNode *currA = headA, *currB = headB;

        while(currA || currB) {
            if(currA) {
                currA = currA->next;
                lenA += 1;
            }

            if(currB) {
                currB = currB->next;
                lenB += 1;
            }
        }

        if(lenA > lenB) swap(headA, headB);
        
        currA = headA, currB = headB;
        for(int i = 0; i < abs(lenA - lenB); ++i) {
            currB = currB->next;
        }

        while(currA && currB) {
            if(currA == currB) return currA; 
            currA = currA->next;
            currB = currB->next;
        }

        return nullptr;
    }
};
