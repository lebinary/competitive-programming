/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2 ms (beats 67.8%)
 * Memory: 19.9 MB (beats 6.0%)
 * Submitted: 2026-01-01 07:36:03 UTC
 * URL: https://leetcode.com/submissions/detail/1870806379/
 */

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy = new ListNode(0);
        priority_queue<tuple<int, ListNode *>, vector<tuple<int, ListNode *>>, greater<tuple<int, ListNode *>>> minHeap;
        for (ListNode *node : lists) {
            if (node == nullptr) continue;
            minHeap.push({node->val, node});
        }

        ListNode *curr = dummy;
        while (!minHeap.empty()) {
            auto [val, node] = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next != nullptr) minHeap.push({node->next->val, node->next});
        }

        return dummy->next;
    }
};

