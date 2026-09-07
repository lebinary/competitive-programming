/*
 * 917. Reverse Only Letters
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.6 MB (beats 3.1%)
 * Submitted: 2026-07-24 04:51:04 UTC
 * URL: https://leetcode.com/submissions/detail/2079086522/
 */

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<tuple<int, char>> st;
        queue<tuple<int, char>> q;

        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                st.push({i, s[i]});
            } else {
                q.push({i, s[i]});
            }
        }

        string res = "";
        for(int i = 0; i < s.size(); ++i) {
            if(!q.empty() && get<0>(q.front()) == i) {
                auto [idx, cha] = q.front();
                q.pop();
                res += cha;
            } else {
                auto [idx, cha] = st.top();
                st.pop();
                res += cha;
            }
        }

        return res; 
    }
};
