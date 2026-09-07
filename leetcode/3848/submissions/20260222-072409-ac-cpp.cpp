/*
 * 3848. Check Digitorial Permutation
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 9.3 MB (beats 52.8%)
 * Submitted: 2026-02-22 07:24:09 UTC
 * URL: https://leetcode.com/submissions/detail/1927184403/
 */

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string s = to_string(n);
        vector<int> freq(10, 0); 
        
        long long res = 0;
        for(char c : s) {
            res += fact(c - '0');
            freq[c - '0']++;
        }
        
        while(res) {
            int digit = res % 10;
            freq[digit]--;
            res = res / 10;
        }

        for(int i = 0; i < 9; ++i){
            if(freq[i] != 0) return false;
        }

        return true;
    }

    long long fact(int n) {
        if(n < 0) return 0;
        long long res = 1;
        for(int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
};
