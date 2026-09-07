/*
 * 646. Maximum Length of Pair Chain
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 26.5 MB (beats 66.2%)
 * Submitted: 2026-04-01 14:17:02 UTC
 * URL: https://leetcode.com/submissions/detail/1965905221/
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [&](auto& pairA, auto& pairB) { 
            return pairA[1] < pairB[1];
        });

        int res = 0, lastEnd = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(pairs[i][0] <= lastEnd) continue;
            res++;
            lastEnd = pairs[i][1];
        }

        return res;
    }
};

/**
maximize non-overlapping intervals
=> sort by end, greedy pick

Why greedy works:
consider pairA and pairB, where pairA[1] < pairB[1], there are 2 cases:
    - non-overlap: pick pairA
    - overlap: still pick pairA 
        because pairA[1] < pairB[1] => leave "more space" for subsequent pick

**/
