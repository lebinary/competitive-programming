#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
