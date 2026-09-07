/*
 * 2013. Detect Squares
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 215 ms (beats 14.2%)
 * Memory: 116.1 MB (beats 29.4%)
 * Submitted: 2025-07-14 11:38:36 UTC
 * URL: https://leetcode.com/submissions/detail/1697446707/
 */


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
