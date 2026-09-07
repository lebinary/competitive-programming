/*
 * 3170. Lexicographically Minimum String After Removing Stars
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 164 ms (beats 27.3%)
 * Memory: 26.4 MB (beats 50.5%)
 * Submitted: 2026-01-03 10:04:09 UTC
 * URL: https://leetcode.com/submissions/detail/1872936848/
 */

class Solution {
  public:
    string clearStars(string s) {
        int n = s.size();
        vector<bool> res(n, true);
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minHeap;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '*')
                minHeap.push({s[i], i * -1});
            else {
                res[i] = false;
                if (!minHeap.empty()) {
                    auto [val, negIdx] = minHeap.top();
                    minHeap.pop();
                    res[-1 * negIdx] = false;
                }
            }
        }

        string resStr = "";
        for (int i = 0; i < n; ++i) {
            if (res[i] == false) continue;
            resStr += s[i];
        }

        return resStr;
    }
};
