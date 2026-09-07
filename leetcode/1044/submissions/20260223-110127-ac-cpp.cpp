/*
 * 1044. Longest Duplicate Substring
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 686 ms (beats 77.7%)
 * Memory: 258.7 MB (beats 61.5%)
 * Submitted: 2026-02-23 11:01:27 UTC
 * URL: https://leetcode.com/submissions/detail/1928415159/
 */

class Solution {
public:
    // Hint used: 2
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
        long long BASE = 26, MOD = 1e9 + 7;

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
