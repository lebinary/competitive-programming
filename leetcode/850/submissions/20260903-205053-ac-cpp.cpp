/*
 * 850. Rectangle Area II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 7 ms (beats 30.9%)
 * Memory: 12.7 MB (beats 66.3%)
 * Submitted: 2026-09-03 20:50:54 UTC
 * URL: https://leetcode.com/submissions/detail/2130091509/
 */

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size(), MOD = 1e9 + 7, area = 0;
        
        vector<vector<int>> xs;
        
        unordered_set<int> ysSet;
        vector<int> ys;
        unordered_map<int, int> yIdx;

        for(int i = 0; i < n; ++i) {
            vector<int>& rec = rectangles[i];
            
            xs.push_back({rec[0], 1, i});
            xs.push_back({rec[2], -1, i});
 
            ysSet.insert(rec[1]);
            ysSet.insert(rec[3]);
        }

        ys.assign(ysSet.begin(), ysSet.end()); 
 
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
 
        for(int i = 0; i < ys.size(); ++i) yIdx[ys[i]] = i;
        vector<int> yCount(ys.size() - 1);
        cout << yCount.size() << endl;
        int j = 0, m = xs.size(), prevX = 0;
        
        while(j < m) {
            int x = xs[j][0];

            long long height = getHeight(yCount, ys) % MOD, width = (x - prevX) % MOD; 
            area = (area + height * width) % MOD;

            while(j < m && xs[j][0] == x) {
                int delta = xs[j][1], recIdx = xs[j][2];
                int y1 = rectangles[recIdx][1], y2 = rectangles[recIdx][3];

                for(int h = yIdx[y1]; h < yIdx[y2]; ++h) {
                    yCount[h] += delta;
                }

                j++;
            }

            prevX = x; 
        }

        return area;   
    }

    long long getHeight(auto& count, auto& ys) {
        long long height = 0;
        
        for(int i = 0; i < count.size(); ++i) {
            if(count[i] > 0) height += ys[i + 1] - ys[i];
        }
        
        return height;
    }
};

/**
Approach 1: sweepline + merge intervals
- sort rectangles by y1
- build xs - loop throught rectangles + sort 
- for every pair [x, x+1]:
    height = merge "active" intervals along the y-axis 
    area += height * (x+1 - x)  

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
