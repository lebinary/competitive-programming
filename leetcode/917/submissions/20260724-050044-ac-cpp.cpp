/*
 * 917. Reverse Only Letters
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.4 MB (beats 3.1%)
 * Submitted: 2026-07-24 05:00:45 UTC
 * URL: https://leetcode.com/submissions/detail/2079097204/
 */

class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        vector<char> resArr(s.size(), '\0');

        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                st.push(s[i]);
            } else {
                resArr[i] = s[i];
            }
        }

        for(int i = 0; i < resArr.size(); ++i) {
            if(resArr[i] == '\0') {
                char c = st.top();
                st.pop();
                resArr[i] = c;
            }
        }

        string res(resArr.begin(), resArr.end());
        return res;
    }
};
