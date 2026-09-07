/*
 * 497. Random Point in Non-overlapping Rectangles
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 12 ms (beats 72.6%)
 * Memory: 73.6 MB (beats 98.6%)
 * Submitted: 2026-03-27 20:47:29 UTC
 * URL: https://leetcode.com/submissions/detail/1961266032/
 */

class Solution {
    vector<vector<int>> rects;
    vector<int> prefix;
    int n;
public:
    Solution(vector<vector<int>>& rects) {
        srand(time(0));
        this->rects.swap(rects);
        this->n = this->rects.size();
        this->prefix.assign(n, 0);
        
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            vector<int>& rect = this->rects[i];
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            sum += (x - a + 1) * (y - b + 1);

            prefix[i] = sum;
        }
    }
    
    vector<int> pick() {
        int v = random(0, prefix.back());

        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(prefix[m] >= v) r = m;
            else l = m + 1;
        }

        vector<int>& rect = rects[l];
        int a = rect[0], b = rect[1], x = rect[2], y = rect[3];

        return {random(a, x), random(b, y)};
    }

    int random(int min, int max) {
        return rand() % (max - min + 1) + min;
    }
};

/**
- For x axis
    - pick random rect * pick random point * weight of the rect
    example: pick rect with width = 4
        => 1/rects * 1/width * width = 1/rects
        => this ensure randomness
- Similarly for y axis

# Approach:
- create a distribution prefix for each rec: example
    prefix[0] = w0 of rects[0]
    prefix[1] = w0 + w1 of rects[1]
    ...

- In pick:
    pick a random rect with weight (x - a) * (y - b)
    pick a random x-point in range [a, x]
    pick a random y-point in range [b, y]

**/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
