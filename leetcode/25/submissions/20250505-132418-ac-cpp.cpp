/*
 * 25. Reverse Nodes in k-Group
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 16.5 MB (beats 39.1%)
 * Submitted: 2025-05-05 13:24:18 UTC
 * URL: https://leetcode.com/submissions/detail/1626110455/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* gPrev = dummy;
        
        while(true) {
            ListNode* kth = getKth(gPrev, k);
            if(!kth) break;

            ListNode* gNext = kth->next;
            ListNode* prev = gNext;
            ListNode* curr = gPrev->next;
            while(curr != gNext){
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            ListNode* tail = gPrev->next; // tail was previously head 
            gPrev->next = kth;
            gPrev = tail;
        }

        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while(curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
