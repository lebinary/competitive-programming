/*
 * 791. Custom Sort String
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 7.7%)
 * Memory: 8.3 MB (beats 69.2%)
 * Submitted: 2026-03-24 14:43:06 UTC
 * URL: https://leetcode.com/submissions/detail/1957857309/
 */

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;

        string res = "";
        for(int i = 0; i < order.size(); ++i) {
            while(freq[order[i]] > 0) {
                res += order[i];
                freq[order[i]]--;
            }
            if(freq[order[i]] == 0) freq.erase(order[i]);
        }

        for(auto it = freq.begin(); it != freq.end(); ++it) {
            while(it->second > 0) {
                res += it->first;
                it->second--;
            }
        }

        return res;
    }
};
