/*
 * 3577. Count the Number of Computer Unlocking Permutations
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 105 ms (beats 5.1%)
 * Memory: 113.3 MB (beats 5.1%)
 * Submitted: 2025-06-09 13:31:07 UTC
 * URL: https://leetcode.com/submissions/detail/1658667456/
 */

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        // SORT
        // valid if exist smaller value, and unlocked
        // 0-index value is the threshold, any number after that must be STRICTLY larger. => 0-index threshold has the smallest value
        // threshold can EXPAND, only upward => many valid thresholds.
        // if a number falls below the 0-index threshold, it cant be unlocked.
        int mod = pow(10, 9) + 7;
        int first = complexity[0];
        set<int> thresholds;
        thresholds.insert(first);

        vector<int> sv(complexity.begin() + 1, complexity.end()); 
        sort(sv.begin(), sv.end());
        for(int i = 0; i < sv.size(); ++i) {
            if(sv[i] <= first || thresholds.lower_bound(sv[i]) == thresholds.begin()) return 0;
            thresholds.insert(sv[i]);
        }
        
        return factorial(sv.size(), mod);
    }

    int factorial(int n, int mod) {
        long long res = 1;
        for(int i = 1; i <= n; ++i) {
            res = (res * i) % mod;
        }
        return res;
    }
};
