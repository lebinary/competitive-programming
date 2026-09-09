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

        t[v] = t[2 * v] ^ t[2 * v + 1];
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, r) ^ query(2 * v + 1, tm, tr, l, r);
    }

    long long query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    cin >> a;

    Seg segTree(a);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        cout << segTree.query(a - 1, b) << endl;
    }
}
