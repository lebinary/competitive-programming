/*
 * 246. Strobogrammatic Number
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 8 MB (beats 52.1%)
 * Submitted: 2026-03-25 20:06:02 UTC
 * URL: https://leetcode.com/submissions/detail/1959288777/
 */

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        unordered_set<char> valid = {'0', '1', '8'};
        unordered_set<char> semiValid = {'6', '9'};

        // contains non-strobogrammatic
        for(int i = 0; i < n; ++i) {
            if(valid.count(num[i]) || semiValid.count(num[i])) continue;
            else return false;
        }

        // check "mirrorness"
        int l = 0, r = n - 1;
        while(l <= r) {
            if(valid.count(num[l]) && valid.count(num[r])) {
                if(num[l] != num[r]) return false;
            } else if(semiValid.count(num[l])) {
                if(num[l] == '6' && num[r] != '9') return false;
                if(num[l] == '9' && num[r] != '6') return false;
            } else {
                if(num[r] == '6' && num[l] != '9') return false;
                if(num[r] == '9' && num[l] != '6') return false;
            }

            l++; r--;
        }
        return true;
    }
};

/**
strobogrammatic number

0, 6, 9, 8

- first scan: make sure given number only contains these
- second scan: 2 pointers to check mirroring
**/
