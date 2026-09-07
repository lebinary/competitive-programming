/*
 * 997. Find the Town Judge
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 65 MB (beats 95.4%)
 * Submitted: 2025-05-11 10:40:20 UTC
 * URL: https://leetcode.com/submissions/detail/1630953566/
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> delta(n+1, 0);

        for (auto& t : trust) {
            delta[t[0]]--;
            delta[t[1]]++;
        }

        for (int i = 1; i < n+1; ++i) {
            if(delta[i] == n-1) return i;
        }

        return -1;
    }
};
