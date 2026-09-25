#include "cp.h"

struct Seg {
    int n; vector<int> t;
    Seg(int n) : n(n), t(4*n) {}
    void build(int v, int tl, int tr, vector<int>& a) {
        if(tr - tl == 1) { t[v] = a[tl]; return; }
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm, a); build(2*v+1, tm, tr, a);
        t[v] = max(t[2*v], t[2*v+1]);
    }
    int descend(int v, int tl, int tr, int delta) {
        if(tr - tl == 1) { t[v] -= delta; return tl; }
        int tm = (tl + tr) / 2;
        int res = delta <= t[2*v] ? descend(2*v, tl, tm, delta) : descend(2*v+1, tm, tr, delta);
        t[v] = max(t[2*v], t[2*v+1]);
        return res;
    }
    int query(int v, int tl, int tr, int l, int r) {
        if(r <= tl || tr <= l) return 0;
        if(l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return max(query(2*v, tl, tm, l, r), query(2*v+1, tm, tr, l, r));
    }
    void build(vector<int>&a) { build(1, 0, n, a); }
    int descend(int delta) { return descend(1, 0, n, delta); }
    int query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> rooms(n); cin >> rooms;

    Seg tree(n);
    tree.build(rooms);

    for(int j = 0; j < m; ++j) {
        int group; cin >> group;
        if(tree.t[1] < group) cout << 0 << ' ';
        else cout << tree.descend(group) + 1 << ' ';
    }
    cout << endl;
}
