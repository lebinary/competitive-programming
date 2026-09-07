/*
 * 246. Strobogrammatic Number
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8.2 MB (beats 14.3%)
 * Submitted: 2026-03-25 20:16:39 UTC
 * URL: https://leetcode.com/submissions/detail/1959294841/
 */

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        unordered_map<char, char> rotate = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        int l = 0, r = n - 1;
        while(l <= r) {
            if(!rotate.count(num[l]) || !rotate.count(num[r])) return false;
            if(rotate[num[l]] != num[r]) return false;
            l++; r--;
        }

        return true;
    }
};

/**
strobogrammatic number

0, 1, 6, 9, 8
# Approach: 2 pointers
- for each pair l and r, check
    - l and r in rotate_map
    - rotate[l] == r 
**/
