/*
 * 249. Group Shifted Strings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 49.2%)
 * Memory: 12.9 MB (beats 11.2%)
 * Submitted: 2026-03-15 07:35:25 UTC
 * URL: https://leetcode.com/submissions/detail/1948859911/
 */

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> group;
        int n = strings.size();

        for(int i = 0; i < n; ++i) {
            string encoded = serialize(strings[i]);
            group[encoded].push_back(strings[i]);
        }

        vector<vector<string>> res;
        for(auto [_, vectors] : group) {
            res.push_back(vectors);
        }

        return res;
    }

    string serialize(string& s) {
        string encoded = "";

        for(int i = 0; i < s.size(); ++i) {
            if(i == 0) {
                encoded += "0";
            } else {
                int num = ((s[i] - s[i -1]) - 'a') % 26;
                encoded += to_string(num);
            }

            if(i <= s.size() - 1) encoded += ".";
        }

        return encoded;
    }
};

/**
# Ideas:
- serialize:
    - same length
    - distance between characters
    - can be negative

"abc" => "0.1.2"
"bcd" => "0.1.2"
"zab" => "0.1.2"

"ba" => "0.25"
"dc" => "0.25"
"az" => "0.25"

**/
