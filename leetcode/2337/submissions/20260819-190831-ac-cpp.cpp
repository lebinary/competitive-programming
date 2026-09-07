/*
 * 2337. Move Pieces to Obtain a String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 35.1%)
 * Memory: 21.9 MB (beats 73.6%)
 * Submitted: 2026-08-19 19:08:32 UTC
 * URL: https://leetcode.com/submissions/detail/2113162299/
 */

class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.size();
        int i = 0, j = 0;

        while(i < n || j < n) {
            while(i < n && start[i] == '_') i++;
            while(j < n && target[j] == '_') j++;
    
            if(start[i] != target[j]) return false;
    
            if(start[i] == 'L' && j > i) return false;

            if(start[i] == 'R' && j < i) return false;
            
            i++; j++;
        }
        
        return true;
    }
};

/**
start  = "_L_R__L___R"
target = "L__R_L____R"

**/
