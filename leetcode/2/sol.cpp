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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *node = dummy;

        int remain = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int newVal = remain;
            if (l1 != nullptr) newVal += l1->val;
            if (l2 != nullptr) newVal += l2->val;

            node->next = new ListNode(newVal % 10);
            node = node->next;
            remain = newVal / 10;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        };

        if (remain > 0) {
            node->next = new ListNode(remain);
        }

        return dummy->next;
    }
};
