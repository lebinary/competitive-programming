/*
 * 370. Range Addition
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 13 ms (beats 20.7%)
 * Memory: 22.8 MB (beats 5.7%)
 * Submitted: 2026-09-09 10:34:27 UTC
 * URL: https://leetcode.com/submissions/detail/2136216703/
 */

struct Seg {
    int n; vector<int> t;

    Seg(int n) : n(n), t(4 * n) {}

    void update(int v, int tl, int tr, int l, int r, int x) {
        if(r <= tl || tr <= l) return;
        if(l <= tl && tr <= r) { t[v] += x; return; }

        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, x);
        update(2 * v + 1, tm, tr, l, r, x);
    }

    int query(int v, int tl, int tr, int i) {
        if(tr - tl == 1) return t[v];

        int tm = (tl + tr) / 2;
        return t[v] + (i < tm ? query(2 * v, tl, tm, i) : query(2 * v + 1, tm, tr, i));
    }

    void update(int l, int r, int x) { update(1, 0, n, l, r, x); }
    int query(int i) { return query(1, 0, n, i); }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        Seg segTree(length);

        for(vector<int>& u : updates) {
            int l = u[0], r = u[1] + 1, inc = u[2];
            segTree.update(l, r, inc);
        }

        for(int i = 0; i < length; ++i) {
            res[i] = segTree.query(i);
        }

        return res;
    }
};
