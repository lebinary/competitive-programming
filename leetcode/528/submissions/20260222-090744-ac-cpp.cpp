/*
 * 528. Random Pick with Weight
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 282 ms (beats 5.0%)
 * Memory: 50.8 MB (beats 5.7%)
 * Submitted: 2026-02-22 09:07:45 UTC
 * URL: https://leetcode.com/submissions/detail/1927260421/
 */

class Solution {
public:
    vector<vector<int>> ranges;
    random_device rd;

    Solution(vector<int>& w) {
        int n = w.size();
        int tot = accumulate(w.begin(), w.end(), 0);

        for(int i = 0; i < n; ++i) {
            if(this->ranges.empty()) {
                this->ranges.push_back({1, w[i]});
                continue;
            }

            vector<int> &prev = this->ranges.back();
            this->ranges.push_back({prev[1] + 1, prev[1] + w[i]});
        }
    }
    
    int pickIndex() {
        int target = random(1, ranges.back()[1]);
        int l = 0, r = ranges.size() - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;

            if(ranges[m][0] <= target && target <= ranges[m][1]) return m;
            else if(ranges[m][1] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }

    int random(int min, int max) {
        mt19937 gen(rd());
        uniform_int_distribution dist(min, max);
        return dist(gen);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
