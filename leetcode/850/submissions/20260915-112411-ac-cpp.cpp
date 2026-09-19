/*
 * 850. Rectangle Area II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.3 MB (beats 31.3%)
 * Submitted: 2026-09-15 11:24:11 UTC
 * URL: https://leetcode.com/submissions/detail/2142528039/
 */

// Segment tree - Range Update, Point Query
// Coverage tree: same as SegTree, but calculate coverage on the way up
struct Seg {
    int n; vector<int> X;
    vector<long long> t, coverage;

    Seg(vector<int>& X) : X(X), n(X.size()), t(4*n), coverage(4*n) {}
    
    void pull(int v, int tl, int tr) {
        if(t[v] > 0) coverage[v] = X[tr] - X[tl];
        else if(tr - tl == 1) coverage[v] = 0;
        else coverage[v] = coverage[2 * v] + coverage[2 * v + 1];
    } 

    void update(int v, int tl, int tr, int l, int r, int x) {
        if(r <= tl || tr <= l) return;
        if(l <= tl && tr <= r) { t[v] += x; pull(v, tl, tr); return; }

        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, x);
        update(2 * v + 1, tm, tr, l, r, x);

        pull(v, tl, tr);
    }

    long long covered() { return coverage[1]; }

    void update(int l, int r, int x) { update(1, 0, n, l, r, x); }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size(), MOD = 1e9 + 7, area = 0;
        vector<vector<int>> ys;
        unordered_set<int> xs;
        
        for(int i = 0; i < n; ++i) {
            const auto& rec = rectangles[i];
            ys.push_back({rec[1], -1, i});
            ys.push_back({rec[3], 1, i});
 
            xs.insert(rec[0]);
            xs.insert(rec[2]);
        }

        sort(ys.begin(), ys.end());

        vector<int> X(xs.begin(), xs.end());
        sort(X.begin(), X.end());
        unordered_map<int, int> xIdx;
        for(int i = 0; i < X.size(); ++i) xIdx[X[i]] = i;

        Seg coverageTree(X);
        int m = ys.size(), j = 0;
        long long totalCoverage = 0;

        while(j < m) {
            int y = ys[j][0];

            while(j < m && ys[j][0] == y) {
                int i = ys[j][2];
                int l = xIdx[rectangles[i][0]], r = xIdx[rectangles[i][2]];

                int delta = -ys[j][1];
 
                coverageTree.update(l, r, delta);
                j++;
            }

            long long width = coverageTree.covered();
            long long height = j >= m ? 0 : (ys[j][0] - y);
            totalCoverage = (totalCoverage + height * width) % MOD;
        }

        return totalCoverage;
    }
};

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

Approach 3: sweepline + coverage tree
- 
**/
