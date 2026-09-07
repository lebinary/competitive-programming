/*
 * 850. Rectangle Area II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 12.1 MB (beats 84.5%)
 * Submitted: 2026-09-05 12:11:24 UTC
 * URL: https://leetcode.com/submissions/detail/2131684555/
 */

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size(), MOD = 1e9 + 7, area = 0;
        sort(rectangles.begin(), rectangles.end(), [&](auto& a, auto& b) {
            if(a[1] == b[1]) return a[3] < b[3];
            return a[1] < b[1];
        });

        vector<vector<int>> xs;
        
        for(int i = 0; i < n; ++i) {
            const auto& rec = rectangles[i];
            xs.push_back({rec[0], i});
            xs.push_back({rec[2], i});
        }

        sort(xs.begin(), xs.end());
        vector<bool> active(n);

        int j = 0, m = xs.size();
        while(j < m) {
            int x = xs[j][0];

            while(j < m && xs[j][0] == x) {
                int i = xs[j][1];
                active[i] = !active[i];
                j++;
            }

            long long height = mergeIntervals(rectangles, active, x);
            long long width = j >= m ? 0 : (xs[j][0] - x);
            area = (area + height * width) % MOD;
        }

        return area;
    }

    long long mergeIntervals(auto& rectangles, auto& active, int x) {
        long long height = 0, prevY = 0;
        
        for(int i = 0; i < rectangles.size(); ++i) {
            if(active[i]) {
                int y1 = rectangles[i][1], y2 = rectangles[i][3];
                
                if(y1 <= prevY) height += y2 > prevY ? y2 - prevY : 0;
                else height += (y2 - y1);

                prevY = max<long long>(prevY, y2);
            }
        }
 
        return height;
    }
};
/**
10: 35 * 12 = 420
22: 45 * 1 = 45
23: 52 * 16 = 832
39: 45 * 28 = 1260
67: 35 * 13 = 455

**/

/**
Approach 1: sweepline + merge intervals
- build xs, each rec produces 2 points - (x1, y1, y2) & (x2, y1, y2)
- sort xs by (x1, y1)
- sweep xs, for each "x value":
    height = merge intervals involved in x value
    width = (x_i+1 - x)

Approach 2: sweepline + active recs along y-axis
- build "ys" - loop through reactangles, extract y values, sort
- build "xs" - loop through reactangles, extract y values, sort

- init rec_count_on_height[j] 
- for each "xs":
    area += get_height(rec_count_on_height, ys) * (x - prev_x)

    go through all events in this "x":
        x, isStart, y1, y2 = event
        
        for j=index(y) in (y1, y2):
            if isStart: 
                rec_count_on_height[j]++
            else 
                rec_count_on_height[j]--
**/
