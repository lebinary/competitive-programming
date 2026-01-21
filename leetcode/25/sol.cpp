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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *dummy2 = dummy;

        ListNode *start = head, *end = head;
        int count = 0;

        while (end != nullptr) {
            count++;
            end = end->next;

            if (count == k) {
                ListNode *prev = end, *curr = start;
                while (curr != end) {
                    ListNode *tmp = curr->next;
                    curr->next = prev;

                    prev = curr;
                    curr = tmp;
                }

                dummy2->next = prev;
                dummy2 = start;
                start = end;
                count = 0;
            }
        }

        return dummy->next;
    }
};
