/*
 * 862. Shortest Subarray with Sum at Least K
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 39 ms (beats 12.9%)
 * Memory: 113.1 MB (beats 5.3%)
 * Submitted: 2026-02-19 03:32:34 UTC
 * URL: https://leetcode.com/submissions/detail/1923886926/
 */

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        
        long long sum = 0;
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix[i + 1] = sum;
        }

        deque<long long> dq;
        for(int j = 0; j < n + 1; ++j) {
            while(!dq.empty() && prefix[dq.back()] > prefix[j]) dq.pop_back();
            dq.push_back(j);

            int lastValidIdx = -1;
            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                lastValidIdx = dq.front();
                dq.pop_front();
            }

            if(lastValidIdx != -1) res = min(res, j - lastValidIdx);
        }

        return res == INT_MAX ? -1 : res;
    }
};

/** 
nums = [2,-1, 2, 2, 1], k = 3
prefix=[2, 1, 3, 5, 6]

solve: prefix[j] - k >= prefix[i-1]

How do you query the inequality efficiently?
- For each j, there are a few candidates i that satisfy the condition, pick the rightmost i. 
- There are a few options: segment tree, multiset and monotone deque/stack 
    => Monotone deque/stack because: candidates consumed (not reused).
        Specifically, assume exist an index j' > j and some candidates i that satisfy the condition:
        then j' - i + 1 > j - i + 1. Hence i is "consumed".
**/
