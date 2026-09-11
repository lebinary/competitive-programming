#include "cp.h"

struct Seg {
    int n;
    vector<int> t;
    Seg(int n) : n(n), t(4 * n) {}

    void build(int v, int tl, int tr, vector<int> &a) {
        if (tr - tl == 1) {
            t[v] = a[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm, tr, a);
    }

    void update(int v, int tl, int tr, int l, int r, int u) {
        if (r <= tl || tr <= l) return;
        if (l <= tl && tr <= r) {
            t[v] += u;
            return;
        }

        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, u);
        update(2 * v + 1, tm, tr, l, r, u);
    }

    int query(int v, int tl, int tr, int i) {
        if (tr - tl == 1) return t[v];

        int tm = (tl + tr) / 2;
        return t[v] + (i < tm ? query(2 * v, tl, tm, i) : query(2 * v + 1, tm, tr, i));
    }

    void build(vector<int> &a) { build(1, 0, n, a); }
    void update(int l, int r, int u) { update(1, 0, n, l, r, u); }
    int query(int i) { return query(1, 0, n, i); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;

    Seg segTree(n);
    segTree.build(a);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            segTree.update(a - 1, b, u);
        } else {
            int k;
            cin >> k;
            cout << segTree.query(k - 1) << endl;
        }
    }
}
