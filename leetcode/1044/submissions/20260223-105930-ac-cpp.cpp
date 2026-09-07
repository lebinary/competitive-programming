/*
 * 1044. Longest Duplicate Substring
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 690 ms (beats 76.4%)
 * Memory: 258.9 MB (beats 61.2%)
 * Submitted: 2026-02-23 10:59:31 UTC
 * URL: https://leetcode.com/submissions/detail/1928413635/
 */

class Solution {
public:
    // Hint used: 1
    string res;

    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 0, r = n;

        while(l < r) {
            int m = l + (r - l + 1) / 2;

            if(validator(s, m)) l = m;
            else r = m - 1;
        }

        return l == n ? "" : res;
    }

    bool validator(string &s, int size) {
        if(size > s.size()) return false;

        unordered_map<long long, int> seen;

        long long key = 0, power = 1;
        long long BASE = 31, MOD = 1e9 + 7;

        for(int j = 0; j < size; ++j) power = power * BASE % MOD;
        
        for(int r = 0; r < s.size(); ++r) {
            key = (key * BASE + (s[r] - 'a')) % MOD;
            
            if(r >= size) {
                long long remove = (s[r - size] - 'a') * power % MOD;
                key = (key - remove + MOD) % MOD;
            } 
            
            if(r < size - 1) continue;

            if(seen.count(key)) {
                string cand = s.substr(seen[key] - size + 1, size);
                string curr = s.substr(r - size + 1, size);

                if(cand == curr) {
                    res = curr;
                    return true;
                }
            }
            seen[key] = r;
        }

        return false;
    }
};
