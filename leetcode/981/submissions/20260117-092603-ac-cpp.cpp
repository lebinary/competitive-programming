/*
 * 981. Time Based Key-Value Store
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 94 ms (beats 8.8%)
 * Memory: 136.6 MB (beats 71.9%)
 * Submitted: 2026-01-17 09:26:03 UTC
 * URL: https://leetcode.com/submissions/detail/1887585425/
 */

class TimeMap {
  public:
    unordered_map<string, vector<pair<string, int>>> map;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (map.count(key) == 0) map[key] = {};
        map[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (map.count(key) == 0) return "";

        int n = map[key].size();
        int l = 0, r = n - 1;

        while (l < r) {
            int m = l + (r - l + 1) / 2;

            if (map[key][m].second <= timestamp) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        return map[key][l].second <= timestamp ? map[key][l].first : "";
    }
};
