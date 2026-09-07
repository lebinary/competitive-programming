/*
 * 3561. Resulting String After Adjacent Removals
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 43 ms (beats 90.2%)
 * Memory: 65.1 MB (beats 12.1%)
 * Submitted: 2025-05-25 03:29:48 UTC
 * URL: https://leetcode.com/submissions/detail/1643649431/
 */

#include <string>

class Solution {
public:
    string resultingString(string s) {
        vector<char> st;

        for(char c : s) {
            if (st.empty()) {
                st.push_back(c);
                continue;
            }

            char topC = st.back();

            if(abs((int)topC - (int)c) % 24 == 1) {
                st.pop_back(); 
            } else {
                st.push_back(c);
            }
        }


        string res;
        for(char c : st) {
            res += c;
        }
        
        return res;
    }
};
