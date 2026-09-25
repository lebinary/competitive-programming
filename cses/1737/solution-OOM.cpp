#include "cp.h"

struct Seg {
    int n;
    vector<long long> t;
    Seg(vector<long long> &a) : n(a.size()), t(4 * n) { build(1, 0, n, a); }

    void build(int v, int tl, int tr, vector<long long> &a) {
        if (tr - tl == 1) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm, tr, a);
        t[v] = t[2 * v] + t[2 * v + 1];
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
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm, tr, l, r);
    }

    void update(int i, long long x) { update(1, 0, n, i, x); }
    long long query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    cin >> a;

    vector<Seg> trees;
    trees.push_back(Seg(a));

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, a;
            long long x;
            cin >> k >> a >> x;
            trees[k - 1].update(a - 1, x);
        } else if (type == 2) {
            int k, a, b;
            cin >> k >> a >> b;

            long long sum = trees[k - 1].query(a - 1, b);
            cout << sum << endl;
        } else {
            int k;
            cin >> k;
            trees.push_back(trees[k - 1]);
        }
    }
}
