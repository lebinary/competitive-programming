/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 111 ms (beats 7.2%)
 * Memory: 19 MB (beats 24.6%)
 * Submitted: 2025-11-19 10:50:55 UTC
 * URL: https://leetcode.com/submissions/detail/1834135430/
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
        if (!listA) return listB;
        if (!listB) return listA;

        ListNode dummy(0);
        ListNode *curr = &dummy;

        while (listA != nullptr && listB != nullptr) {
            if (listA->val <= listB->val) {
                curr->next = listA;
                listA = listA->next;
            } else {
                curr->next = listB;
                listB = listB->next;
            }
            curr = curr->next;
        }

        curr->next = listA != nullptr ? listA : listB;

        return dummy.next;
    }
};

