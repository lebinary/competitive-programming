/*
 * 1047. Remove All Adjacent Duplicates In String
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 4 ms (beats 70.9%)
 * Memory: 14.8 MB (beats 13.5%)
 * Submitted: 2026-03-25 07:30:05 UTC
 * URL: https://leetcode.com/submissions/detail/1958602822/
 */

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        vector<char> st;

        for(int i = 0; i < n; ++i) {
            if(st.empty()) {
                st.push_back(s[i]);
                continue;
            }

            if(s[i] == st.back()) st.pop_back();
            else st.push_back(s[i]);
        }

        string res(st.begin(), st.end());
        return res;
    }
};

/**
# Approach: Stack
**/
