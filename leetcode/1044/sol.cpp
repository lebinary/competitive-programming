#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    // Hint used: 2
    // Time taken: 54 m 47 s
    string res;

    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 0, r = n;

        while (l < r) {
            int m = l + (r - l + 1) / 2;

            if (validator(s, m))
                l = m;
            else
                r = m - 1;
        }

        return l == n ? "" : res;
    }

    bool validator(string &s, int size) {
        if (size > s.size()) return false;

        unordered_map<long long, int> seen;

        long long key = 0, power = 1;
        long long BASE = 26, MOD = 1e9 + 7;

        for (int j = 0; j < size; ++j) power = power * BASE % MOD;

        /**
            hash("abc") = a.base^2 + b.base^1 + c
        **/
        for (int r = 0; r < s.size(); ++r) {
            key = (key * BASE + (s[r] - 'a')) % MOD;

            if (r >= size) {
                long long remove = (s[r - size] - 'a') * power % MOD;
                key = (key - remove + MOD) % MOD;
            }

            if (r < size - 1) continue;

            if (seen.count(key)) {
                string cand = s.substr(seen[key] - size + 1, size);
                string curr = s.substr(r - size + 1, size);

                if (cand == curr) {
                    res = curr;
                    return true;
                }
            }
            seen[key] = r;
        }

        return false;
    }
};

/**
Notes on picking the right MOD (to avoid overflow)

With long long key:
- can store 2^63 - 1 = 10^18 * 8
- key * BASE < 10^18 * 8
<=> MOD * BASE < 10^18 * 8
<=> MOD < (10^18 * 8) / BASE
 => MOD := 10^7 is reasonable choice

With int key:
- can store 2^31 - 1 = 10^9 * 2
- key * BASE < 10^9 * 2
<=> MOD * BASE < 10^9 * 2
<=> MOD < (10^9 * 2) / BASE
 => MOD := 10^7 still works!

**/
