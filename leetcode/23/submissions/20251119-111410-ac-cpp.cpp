/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 3 ms (beats 61.9%)
 * Memory: 18.3 MB (beats 92.8%)
 * Submitted: 2025-11-19 11:14:11 UTC
 * URL: https://leetcode.com/submissions/detail/1834151091/
 */


class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> minHeap(cmp);

        for (ListNode *node : lists) {
            if (node == nullptr) continue;
            minHeap.push(node);
        }

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while (!minHeap.empty()) {
            ListNode *minNode = minHeap.top();
            minHeap.pop();

            curr->next = minNode;
            curr = curr->next;

            if (minNode->next != nullptr) minHeap.push(minNode->next);
        }

        return dummy->next;
    }
};
