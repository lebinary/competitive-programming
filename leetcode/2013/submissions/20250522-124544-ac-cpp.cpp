/*
 * 2013. Detect Squares
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 173 ms (beats 15.3%)
 * Memory: 115.7 MB (beats 29.4%)
 * Submitted: 2025-05-22 12:45:45 UTC
 * URL: https://leetcode.com/submissions/detail/1641225277/
 */

class DetectSquares {
    unordered_map<long, int> map;
public:
    DetectSquares() {}

    long encode(int x, int y) {
        return static_cast<long>(x) << 32 | static_cast<long>(y);
    }

    vector<int> decode(long key) {
        int x = static_cast<int>(key >> 32);
        int y = static_cast<int>(key & 0xFFFFFFFF);
        return {x, y};
    }
    
    void add(vector<int> point) {
        long key = encode(point[0], point[1]);
        if(map.find(key) == map.end()) map[key] = 0;
        map[key]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int qx = point[0], qy = point[1];
        for (auto& [key, val] : map) {
            vector<int> p = decode(key);
            int x = p[0], y = p[1];

            // not forming a diagonal
            if(abs(qx - x) != abs(qy - y) || (qx == x && qy == y)) continue;
            
            long key1 = encode(qx, y);
            int val1 = map.find(key1) == map.end() ? 0 : map[key1];

            long key2 = encode(x, qy);
            int val2 = map.find(key2) == map.end() ? 0 : map[key2];

            res += val * val1 * val2;
        }

        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
