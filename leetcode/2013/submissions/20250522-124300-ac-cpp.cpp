/*
 * 2013. Detect Squares
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 170 ms (beats 15.3%)
 * Memory: 102.7 MB (beats 34.8%)
 * Submitted: 2025-05-22 12:43:00 UTC
 * URL: https://leetcode.com/submissions/detail/1641223429/
 */

class DetectSquares {
    unordered_map<string, int> freqs;
public:
    DetectSquares() {}

    void add(vector<int> point) {
        string key = to_string(point[0]) + ':' + to_string(point[1]);

        if(freqs.find(key) == freqs.end()) freqs[key] = 0;
        freqs[key]++; 
    }
    
    int count(vector<int> point) {
        int res = 0;
        int qx = point[0], qy = point[1];
        for(auto it = freqs.begin(); it != freqs.end(); ++it) {
            string key = it->first;
            int pos = key.find(':');
            int x = stoi(key.substr(0, pos));
            int y = stoi(key.substr(pos + 1));

            bool isDiag = abs(qx - x) == abs(qy - y) && abs(qx - x) > 0;
            if(isDiag) {
                int diagCount = it->second;

                string key1 = to_string(qx) + ':' + to_string(y);
                int point1Freq = freqs.find(key1) == freqs.end() ? 0 : freqs[key1];

                string key2 = to_string(x) + ':' + to_string(qy);
                int point2Freq = freqs.find(key2) == freqs.end() ? 0 : freqs[key2];

                res += diagCount * point1Freq * point2Freq;
            }
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
