/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 19.6 MB (beats 27.5%)
 * Submitted: 2025-05-05 13:46:03 UTC
 * URL: https://leetcode.com/submissions/detail/1626125647/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* curr = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }
        
        if(list1) {
            curr->next = list1;
        }else{
            curr->next = list2;
        }


        return dummy->next;
    }
};
