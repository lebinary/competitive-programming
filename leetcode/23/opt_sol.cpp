#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
