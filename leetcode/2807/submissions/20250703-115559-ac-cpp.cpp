/*
 * 2807. Insert Greatest Common Divisors in Linked List
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 36.2 MB (beats 5.5%)
 * Submitted: 2025-07-03 11:56:00 UTC
 * URL: https://leetcode.com/submissions/detail/1684988718/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
