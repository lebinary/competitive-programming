/*
 * 2337. Move Pieces to Obtain a String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 39 ms (beats 7.4%)
 * Memory: 24.7 MB (beats 18.5%)
 * Submitted: 2026-08-19 18:51:29 UTC
 * URL: https://leetcode.com/submissions/detail/2113145668/
 */

class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.size();
        stack<char> st;
        
        for(int i = 0; i < n; ++i) {
            if(target[i] == 'L') st.push('L');
            
            if(start[i] == 'R') st.push('R');
            
            if(start[i] == 'L'){
                if(st.empty() || st.top() == 'R') return false;
                st.pop();
            }
        }

        while(!st.empty()) {
            if(st.top() == 'L') return false;
            st.pop(); 
        }

        for(int i = n - 1; i >= 0; --i) {
            if(target[i] == 'R') st.push('R');
            
            if(target[i] == 'L') st.push('L');
            
            if(start[i] == 'R') {
                if(st.empty() || st.top() == 'L') return false;
                st.pop();
            }

        }

        while(!st.empty()) {
            if(st.top() == 'R') return false;
            st.pop(); 
        }

        return true;
    }
};

/**
start  = "_L_R__L___R"
target = "L__R_L____R"

**/
