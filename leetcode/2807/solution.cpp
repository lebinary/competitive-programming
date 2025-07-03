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
    vector<int> dp;
    int mod;

  public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            int a = curr->val, b = curr->next->val;
            if (a < b) swap(a, b);
            int gcd = euclideanAlg(a, b);

            ListNode *newNode = new ListNode(gcd, curr->next);
            curr->next = newNode;

            curr = newNode->next;
        }

        return head;
    }

    int euclideanAlg(int a, int b) {
        if (b == 0) return a;
        return euclideanAlg(b, a % b);
    }
};
