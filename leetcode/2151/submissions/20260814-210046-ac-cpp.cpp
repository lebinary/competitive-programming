/*
 * 2151. Maximum Good People Based on Statements
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 39 ms (beats 43.7%)
 * Memory: 12 MB (beats 21.0%)
 * Submitted: 2026-08-14 21:00:46 UTC
 * URL: https://leetcode.com/submissions/detail/2107056632/
 */

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), res = 0;
        vector<int> person(n, 0);
        dfs(statements, res, n, person, 0);
        return res;
    }

    void dfs(vector<vector<int>>& statements, int& res, int& n, vector<int>& person, int i) {
        if(i >= n) {
            if(valid(statements, n, person)) {
                int count = accumulate(person.begin(), person.end(), 0);
                res = max(res, count);
            }
            return;
        }

        // assume good person
        person[i] = 1;
        dfs(statements, res, n, person, i + 1);

        // assume bad person
        person[i] = 0;
        dfs(statements, res, n, person, i + 1);
    }

    bool valid(vector<vector<int>>& statements, int& n, vector<int>& person) {
        for(int i = 0; i < n; ++i) {
            if(person[i] == 1) {
                for(int j = 0; j < n; ++j) {
                    if(statements[i][j] != 2 && statements[i][j] - person[j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
/**
Approach: Backtracking 
- for each person, theres 2 possibility: good or bad, try all possibilities, only record the one with valid
What valid means?
    if the current path say person ith is good, but the statement he made has contradiction then its invalid
    else: valid
**/
