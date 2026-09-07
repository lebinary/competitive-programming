/*
 * 1071. Greatest Common Divisor of Strings
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 11 ms (beats 7.4%)
 * Memory: 20.9 MB (beats 7.0%)
 * Submitted: 2025-05-16 12:08:14 UTC
 * URL: https://leetcode.com/submissions/detail/1635517068/
 */

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() > str2.size()) {
            swap(str1, str2);
        }
        
        string res = ""; 
        for(int l = 1; l <= str1.size(); l++) {
            string prefix = str1.substr(0, l);

            if(str1.size() % prefix.size() != 0) continue;
            if(str2.size() % prefix.size() != 0) continue;

            int i = 0;
            while(i < str1.size()) {
                if(str1.substr(i, l) != prefix) break;
                i += l;
            }
            if(i != str1.size()) continue; 


            i = 0;
            while(i < str2.size()) {
                if(str2.substr(i, l) != prefix) break;
                i += l;
            }
            if(i != str2.size()) continue;

            res = prefix;
        }

        return res;
    }
};
