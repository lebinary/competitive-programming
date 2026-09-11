#include "cp.h"

/**

update range [l, r) => t[p] = p - l + 1
i.e
    [3,6) => t[3] = 1, t[4] = 2, t[5] = 3. This is a linear function: y = ax + b. With a = 1, b = 1 - l
    This linear function is constant across the additions - "position p gets p - l + 1"

Since linear function: y = ax + b. With a = 1, b = 1 - l
=> ∑ y[l..r) = ∑ (a * p[l...r) + b)
              = a * ∑p[l..r) + b * (r - l)

so the apply() becomes:
t[v] += [ a * ∑p[l..r) + b * (r - l) ]
lz[v] += {a, b}

Visually: segment tree store the sum of "dyatic intervals" a node v owns.
t[v]
|           /
|          /
|   /  /  /
|  /  /  /
| /     /
------------------------p

 */

struct Seg {
    int n;
    vector<int> t, lza, lzb;
    Seg(int n) : n(n), t(4 * n), lza(4 * n), lzb(4 * n) {}

    void apply(int v, int tl, int tr, int a, int b) {
        int s = (tl + tr - 1) * (tr - tl) / 2;
        t[v] += a * s + b * (tr - tl);

        lza[v] += a;
        lzb[v] += b;
    }

    void push(int v, int tl, int tr) {
        if (!lza[v] && !lzb[v]) return;

        int tm = (tl + tr) / 2;
        apply(2 * v, tl, tm, lza[v], lzb[v]);
        apply(2 * v + 1, tm, tr, lza[v], lzb[v]);

        lza[v] = 0;
        lzb[v] = 0;
    }

    void build(int v, int tl, int tr, vector<int> &a) {
        if (tr - tl == 1) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm, tr, a);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    void update(int v, int tl, int tr, int l, int r, int a, int b) {
        if (r <= tl || tr <= l) return;
        if (l <= tl && tr <= r) {
            apply(v, tl, tr, a, b);
            return;
        }

        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, a, b);
        update(2 * v + 1, tm, tr, l, r, a, b);

        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) return t[v];

        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm, tr, l, r);
    }

    void build(vector<int> &a) { build(1, 0, n, a); }
    void update(int l, int r, int a, int b) { update(1, 0, n, l, r, a, b); }
    int query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    Seg segTree(n);
    segTree.build(a);

    for (int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;

        int l = a - 1, r = b;
        if (type == 1) {
            segTree.update(l, r, 1, 1 - l);
        } else {
            cout << segTree.query(l, r) << endl;
        }
    }
}
