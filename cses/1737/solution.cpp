#include "cp.h"

/**
 Persistent Tree: benefit is avoid OOM
 - With normal SegTree: new "update" create new "tree", for q queries, SC: O(n + q*n)
 - With persistent tree: new "update" only add new nodes, for q queries, SC: O(n + q*logn)
 */

struct Node {
    long long sum;
    int l, r;
};

struct Seg {
    int n;
    vector<Node> pool;
    Seg(int n) : n(n) {}

    int build(int tl, int tr, vector<long long> &a) {
        if (tr - tl == 1) {
            pool.push_back({a[tl], -1, -1});
            return pool.size() - 1;
        }
        int tm = (tl + tr) / 2;
        int l = build(tl, tm, a), r = build(tm, tr, a);
        pool.push_back({pool[l].sum + pool[r].sum, l, r});
        return pool.size() - 1;
    }

    int update(int v, int tl, int tr, int i, long long x) {
        if (tr - tl == 1) {
            pool.push_back({x, -1, -1});
            return pool.size() - 1;
        }
        int tm = (tl + tr) / 2;
        int l = pool[v].l, r = pool[v].r;
        if (i < tm)
            l = update(l, tl, tm, i, x);
        else
            r = update(r, tm, tr, i, x);
        pool.push_back({pool[l].sum + pool[r].sum, l, r});
        return pool.size() - 1;
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) return pool[v].sum;
        int tm = (tl + tr) / 2;
        return query(pool[v].l, tl, tm, l, r) + query(pool[v].r, tm, tr, l, r);
    }

    int build(vector<long long> &a) { return build(0, n, a); };
    int update(int v, int i, long long x) { return update(v, 0, n, i, x); }
    long long query(int v, int l, int r) { return query(v, 0, n, l, r); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    cin >> a;

    vector<int> roots;
    Seg persistentTree(n);
    int rootIdx = persistentTree.build(a);
    roots.push_back(rootIdx);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) { // TC: O(logn)
            int k, a;
            long long x;
            cin >> k >> a >> x;
            roots[k - 1] = persistentTree.update(roots[k - 1], a - 1, x);
        } else if (type == 2) { // TC: O(logn)
            int k, a, b;
            cin >> k >> a >> b;

            long long sum = persistentTree.query(roots[k - 1], a - 1, b);
            cout << sum << endl;
        } else { // TC: O(1)
            int k;
            cin >> k;
            roots.push_back(roots[k - 1]);
        }
    }
}
