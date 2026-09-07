/*
 * 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 2 ms (beats 67.8%)
 * Memory: 18.3 MB (beats 92.8%)
 * Submitted: 2026-03-10 12:44:48 UTC
 * URL: https://leetcode.com/submissions/detail/1943915197/
 */

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        struct cmp {
            bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        for(ListNode* node : lists) {
            if(node) minHeap.push(node);
        }
        
        while(!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            curr->next = node;
            curr = curr->next;
            
            if(node->next) minHeap.push(node->next);
        }

        return dummy->next;
    }
};

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
