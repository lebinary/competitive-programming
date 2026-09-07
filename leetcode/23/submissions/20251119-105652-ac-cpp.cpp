/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 103 ms (beats 10.0%)
 * Memory: 18.3 MB (beats 82.7%)
 * Submitted: 2025-11-19 10:56:53 UTC
 * URL: https://leetcode.com/submissions/detail/1834139453/
 */

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *merged = nullptr;

        for (ListNode *list : lists) {
            merged = merge(merged, list);
        }

        return merged;
    }

    ListNode *merge(ListNode *listA, ListNode *listB) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (listA != nullptr && listB != nullptr) {
            if (listA->val >= listB->val) {
                curr->next = listB;
                listB = listB->next;
            } else {
                curr->next = listA;
                listA = listA->next;
            }
            curr = curr->next;
        }

        curr->next = listA != nullptr ? listA : listB;

        return dummy->next;
    }
};
