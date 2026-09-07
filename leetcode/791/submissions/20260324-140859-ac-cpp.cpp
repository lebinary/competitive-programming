/*
 * 791. Custom Sort String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.6 MB (beats 9.7%)
 * Submitted: 2026-03-24 14:09:00 UTC
 * URL: https://leetcode.com/submissions/detail/1957823563/
 */

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> score;
        for(int i = 0; i < order.size(); ++i) score[order[i]] = i;

        vector<pair<int, char>> permuteS(s.size());
        for(int i = 0; i < s.size(); ++i) {
            permuteS[i] = {score[s[i]], s[i]};
        }

        sort(permuteS.begin(), permuteS.end());
        
        string res(s.size(), ' ');
        for(int i = 0; i < permuteS.size(); ++i) {
            res[i] = permuteS[i].second;
        }

        return res;
    }
};
