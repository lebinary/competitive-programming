#include "cp.h"

struct Seg {
    int n; vector<int> t, pre;
    Seg(int n) : n(n), t(4 * n), pre(4 * n) {}

    void build(int v, int tl, int tr, vector<int>& a) {
        if(tr - tl == 1) { t[v] = a[tl]; pre[v] = max((int)0, a[tl]); return; }
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm, a); build(2*v+1, tm, tr, a);
        t[v] = t[2*v] + t[2*v+1]; pre[v] = max(pre[2*v], t[2*v] + pre[2*v+1]);
    }

    void update(int v, int tl, int tr, int i, int x) {
        if(tr - tl == 1) { t[v] = x; pre[v] = max((int)0, x); return; }
        int tm = (tl + tr) / 2;
        if(i < tm) update(2*v, tl, tm, i, x);
        else update(2*v+1, tm, tr, i, x);
        t[v] = t[2*v] + t[2*v+1]; pre[v] = max(pre[2*v], t[2*v] + pre[2*v+1]);
    }

    tuple<int,int> query(int v, int tl, int tr, int l, int r) {
        if(r <= tl || tr <= l) return {0, 0};
        if(l <= tl && tr <= r) return {t[v], pre[v]};
        int tm = (tl + tr) / 2;

        auto [leftSum, leftPre] = query(2*v, tl, tm, l, r);
        auto [rightSum, rightPre] = query(2*v+1, tm, tr, l, r);

        return {leftSum + rightSum, max(leftPre, leftSum + rightPre)};
    }

    void build(vector<int>& a) { build(1, 0, n, a); }
    void update(int i, int x) { update(1, 0, n, i, x); }
    tuple<int, int> query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;

    Seg tree(n);
    tree.build(a);

    for(int i = 0; i < q; ++i) {
        int t, x, y; cin >> t >> x >> y;
        if(t == 1) tree.update(x - 1, y);
        else {
            auto [total, maxPre] = tree.query(x - 1, y);
            cout << maxPre << '\n';
        }
    }
}
