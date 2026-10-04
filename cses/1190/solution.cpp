#include "cp.h"

struct SegMax {
    int n; vector<int> sum, prefix, suffix, res;
    SegMax(int n) : n(n), sum(4*n), prefix(4*n), suffix(4*n), res(4*n) {}
    SegMax(vector<int>& a) : SegMax(a.size()) {}

    void ops(int v) {
        sum[v] = sum[2*v] + sum[2*v+1];
        prefix[v] = max(prefix[2*v], sum[2*v] + prefix[2*v+1]);
        suffix[v] = max(suffix[2*v+1], sum[2*v+1] + suffix[2*v]);
        res[v] = max({res[2*v], res[2*v+1], suffix[2*v] + prefix[2*v+1]});
    }

    void build(int v, int tl, int tr, vector<int>& a) {
        if(tr - tl == 1) {
            sum[v] = prefix[v] = suffix[v] = res[v] =  a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm, a); build(2*v+1, tm, tr, a);
        ops(v);
    }

    int update(int v, int tl, int tr, int i, int x) {
        if(tr - tl == 1) {
            sum[v] = prefix[v] = suffix[v] = res[v] = x;
            return res[v];
        }

        int tm = (tl + tr) / 2;
        if(i < tm) update(2*v, tl, tm, i, x);
        else update(2*v+1, tm, tr, i, x);

        ops(v);
        return res[v];
    }

    void build(vector<int>& a) { build(1, 0, n, a); }
    int update(int i, int x) { return update(1, 0, n, i, x); }
};

 void solve() {
     int n, q; cin >> n >> q;
     vector<int> nums(n); cin >> nums;

     SegMax segmax(n);
     segmax.build(nums);

     for(int i = 0; i < q; ++i) {
         int k, x; cin >> k >> x;
         cout << max<int>(0, segmax.update(k-1, x)) << '\n';
     }
}
