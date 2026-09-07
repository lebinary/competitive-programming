/*
 * 271. Encode and Decode Strings
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 33 ms (beats 47.2%)
 * Memory: 27.8 MB (beats 40.1%)
 * Submitted: 2025-10-07 09:33:20 UTC
 * URL: https://leetcode.com/submissions/detail/1794034313/
 */


class Codec {
  public:
    char SPECIAL = '#';

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string e = "";
        for (string s : strs) {
            e += to_string(s.size()) + SPECIAL + s;
        }
        return e;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> d;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] != SPECIAL) j++;

            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            d.push_back(s.substr(i, length));
            i += length;
        }
        return d;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
