/*
 * 673. Number of Longest Increasing Subsequence
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 99.8%)
 * Memory: 19.6 MB (beats 5.1%)
 * Submitted: 2026-09-18 19:13:57 UTC
 * URL: https://leetcode.com/submissions/detail/2146085620/
 */

struct LIS {
    int len = 0, cnt = 0;
};

struct Seg {
    int n; vector<LIS> t;
    Seg(int n) : n(n), t(4*n) {}

    LIS op(const LIS& lisa, const LIS& lisb) { // op need to be associative
        if(lisa.len == lisb.len) return {lisa.len, lisa.cnt + lisb.cnt};
        return lisa.len > lisb.len ? lisa : lisb;
    }

    void update(int v, int tl, int tr, int i, LIS& delta) {
        if(tr - tl == 1) { t[v] = op(t[v], delta); return; }
        int tm = (tl + tr) / 2;
        if(i < tm) update(2*v, tl, tm, i, delta);
        else update(2*v+1, tm, tr, i, delta);
        t[v] = op(t[2*v], t[2*v+1]);
    }

    LIS query(int v, int tl, int tr, int l, int r) {
        if(r <= tl || tr <= l) return {0, 0};
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return op(query(2*v, tl, tm, l, r), query(2*v+1, tm, tr, l, r)); 
    }

    void update(int i, LIS& x) { update(1, 0, n, i, x); }
    LIS query(int l, int r) { return query(1, 0, n, l, r); }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        unordered_map<int, int> rank;
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for(int k = 0; k < vals.size(); ++k) rank[vals[k]] = k;
        
        Seg segTree(n);

        for(int i = 0; i < n; ++i) {
            int r = rank[nums[i]];
            LIS best = segTree.query(0, r);
            LIS delta = best.len == 0 ? LIS{1, 1} : LIS{best.len + 1, best.cnt};
            segTree.update(r, delta);
        }

        LIS lis = segTree.query(0, n);
        return lis.cnt;
    }
};

/**
Approach 1: DP on each starting position and prev position O(n^2)
- For every position i and prev position j, 
    Recurse forward and return the largest strictly increasing subsequence and it's count/freq. 
    Each position i and prev j will have 2 sets of values: 
        If one subsequence is larger than the other, return that set, 
        Else (meaning the 2 sets have equal subsequence length), return the sum of both sets' count

Approach 2: Bottom-up DP
- len[], count[] represent "maximum len, count of that maximum len ending at i"
- for each i, j pair (j < i)
    if nums[j] < nums[i]:
        if len[j] + 1 > len[i]:
            len[i] = len[j] + 1
            count[i] = count[j]
        
        elif len[j] + 1 == len[i]:
            count[i] += count[j]

Approach 3: Segment Tree - along the rank-axis, with the following operation 
- associative op:
    if lenA > lenB: return {lenA, cntA}
    if lenB > lenA: return {lenB, cntB}
    return {lenA, cntA + cntB} 

**/
