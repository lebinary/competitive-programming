/*
 * 339. Nested List Weight Sum
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 4.8%)
 * Memory: 12.2 MB (beats 54.5%)
 * Submitted: 2026-03-10 12:13:33 UTC
 * URL: https://leetcode.com/submissions/detail/1943892818/
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0, depth = 1;
        queue<NestedInteger*> q;

        for(NestedInteger& ni : nestedList) {
            if(ni.isInteger()) res += ni.getInteger() * depth;
            else {
                vector<NestedInteger>& nl = ni.getList();
                for(NestedInteger& ni : nl) q.push(&ni);
            }
        }

        while(!q.empty()) {
            int n = q.size();
            depth++;

            for(int i = 0; i < n; ++i) {
                NestedInteger* ni = q.front();
                q.pop();

                if(ni->isInteger()) {
                    res += ni->getInteger() * depth;
                } else {
                    vector<NestedInteger>& nl = ni->getList();
                    for(NestedInteger& ni : nl) q.push(&ni);
                }
            }
        }

        return res;
    }
};

/**
# Clarifying:
- "depth" is the level of nested list that element in

Approach 1:
- Use a queue << NestedInteger
- while(!q.empty):
    ni = q.pop()

    for item : ni:
        if item is integer: res += depth
        else q << item
- return res
**/
