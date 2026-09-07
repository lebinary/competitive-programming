/*
 * 67. Add Binary
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.2 MB (beats 16.9%)
 * Submitted: 2026-02-15 07:38:10 UTC
 * URL: https://leetcode.com/submissions/detail/1919835484/
 */

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
        int n = a.size(), m = b.size();
        string res = "";

        int ex = 0;
        for(int i = n - 1; i >= 0; i--) {
            int x = ex;
            x += (a[i] - '0');
            if(i - n + m >= 0) x += (b[i - n + m] - '0');
            res += to_string(x % 2);
            ex = x / 2;
        }

        if(ex > 0) res += "1";

        reverse(res.begin(), res.end());
        return res;
    }
};

