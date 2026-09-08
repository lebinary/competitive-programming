#include "cp.h"

struct Seg {
    int n;
    vector<long long> t;
    Seg(int n) : n(n), t(4 * n, INF) {};

    void build(int v, int tl, int tr, vector<long long> &a) {
        if (tr - tl == 1) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm, tr, a);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int i, long long x) {
        if (tr - tl == 1) {
            t[v] = x;
            return;
        }

        int tm = (tl + tr) / 2;
        if (i < tm)
            update(2 * v, tl, tm, i, x);
        else
            update(2 * v + 1, tm, tr, i, x);

        t[v] = min(t[2 * v], t[2 * v + 1]);
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return INF;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return min(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm, tr, l, r));
    }

    void build(vector<long long> &a) { build(1, 0, n, a); }
    void update(int i, long long x) { update(1, 0, n, i, x); }
    long long query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    cin >> a;

    Seg segTree(n);
    segTree.build(a);

    for (int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            segTree.update(a - 1, b);
        else
            cout << segTree.query(a - 1, b) << endl;
    }
}
