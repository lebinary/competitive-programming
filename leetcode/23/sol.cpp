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
