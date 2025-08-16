#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
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
    void reorderList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode *curr0 = head;
        ListNode *curr1 = prev;
        while (curr0 && curr1) {
            ListNode *tmp0 = curr0->next;
            ListNode *tmp1 = curr1->next;

            curr0->next = curr1;
            curr1->next = tmp0;

            curr0 = tmp0;
            curr1 = tmp1;
        }
    }
};
