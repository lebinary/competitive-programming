/*
 * 1071. Greatest Common Divisor of Strings
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 19.2%)
 * Memory: 10.6 MB (beats 11.6%)
 * Submitted: 2025-05-16 12:24:38 UTC
 * URL: https://leetcode.com/submissions/detail/1635527304/
 */

class Solution {
    string str1;
    string str2;

public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) {
            swap(str1, str2);
        }
        this->str1 = str1;
        this->str2 = str2;
        
        for(int l = str1.size(); l > 0; l--) {
            if(isDivisor(l)) return str1.substr(0, l);
        }

        return "";
    }
private:
    bool isDivisor(int l) {
        if(str1.size() % l || str2.size() % l) return false;
        int f1 = str1.size() / l;
        int f2 = str2.size() / l;

        string divisor = str1.substr(0,l);
        string s = "";
        for(int i = 0; i < f1; i++) {
            s += divisor;
        }
        if(s != str1) return false;

        s = "";
        for(int i = 0; i < f2; i++) {
            s += divisor;
        }
        if(s != str2) return false;

        return true;
    }
};
