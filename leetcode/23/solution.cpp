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
        ListNode *merged;
        for (ListNode *list : lists) {
            merged = merge(merged, list);
        }

        return merged;
    }

    ListNode *merge(ListNode *listA, ListNode *listB) {
        ListNode *dummy;
        ListNode *curr;

        while (listA != nullptr && listB != nullptr) {
            if (listA->val <= listB->val) {
                curr->next = listA;
                listA = listA->next;
            } else {
                curr->next = listB;
                listB = listB->next;
            }
        }

        curr->next = listA != nullptr ? listA : listB;

        return dummy->next;
    }
};
