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

class DetectSquares {
    unordered_map<long, int> freqs;

  public:
    DetectSquares() {}

    long en(vector<int> point) { return static_cast<long>(point[0]) << 32 | static_cast<long>(point[1]); }

    vector<int> de(long key) { return {static_cast<int>(key >> 32), static_cast<int>(key)}; }

    void add(vector<int> point) {
        long k = en(point);
        if (freqs.count(k) == 0) freqs[k] = 0;
        freqs[k]++;
    };

    int count(vector<int> point) {
        int res = 0;
        int qx = point[0], qy = point[1];
        for (auto &[k, v] : freqs) {
            vector<int> p = de(k);
            int x = p[0], y = p[1];

            // cannot form "perfect" diagonals
            if ((qx == x && qy == y) || abs(qx - x) != abs(qy - y)) continue;

            // check other 2 corners
            long k1 = en({qx, y}), k2 = en({x, qy});
            if (freqs.count(k1) == 0 || freqs.count(k2) == 0) continue;

            res += v * freqs[k1] * freqs[k2];
        }

        return res;
    }
};
