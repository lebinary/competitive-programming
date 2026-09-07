/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2 ms (beats 67.8%)
 * Memory: 18.6 MB (beats 48.8%)
 * Submitted: 2026-04-02 10:57:22 UTC
 * URL: https://leetcode.com/submissions/detail/1966725139/
 */

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i = 0; i < k; ++i) {
            if(lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while(!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;
            if(node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};


/**
# Approach:
- Store a minHeap of k size
- Pick the smallest from the heap, iterate
**/





/**
Use heap size n - lists size

1->4->5
1->3->4
2->6

heap=[1,1,2]
    dummy -> 1
heap=[4,1,2]
    dummy -> 1 -> 1
heap=[4,3,2]
    dummy -> 1 -> 1
heap=[4,3,6]
    dummy -> 1 -> 1 -> 2
heap=[4,3,6]
    dummy -> 1 -> 1 -> 2 -> 3
heap=[4,4,6]
    dummy -> 1 -> 1 -> 2 -> 3 -> 4 
....

**/
