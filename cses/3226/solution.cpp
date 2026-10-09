#include "cp.h"

struct Node { int sum, prefix, suffix, largest; };

struct SegMax {
    int n; vector<int> sum, prefix, suffix, largest;
    SegMax(int n) : n(n), sum(4*n), prefix(4 * n), suffix(4 * n), largest(4 * n) {}

    Node merge(const Node& L, const Node& R) {
        return {
            L.sum + R.sum,
            max(L.prefix, L.sum + R.prefix),
            max(R.suffix, R.sum + L.suffix),
            max({L.largest, R.largest, L.suffix + R.prefix})
        };
    }

    void build (int v, int tl, int tr, vector<int>& a) {
        if(tr - tl == 1) {
            sum[v] = a[tl];
            prefix[v] = suffix[v] = largest[v] = max<int>(0, a[tl]);
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a); build(2 * v + 1, tm, tr, a);

        Node leftChild = {sum[2*v], prefix[2*v], suffix[2*v], largest[2*v]};
        Node rightChild = {sum[2*v+1], prefix[2*v+1], suffix[2*v+1], largest[2*v+1]};
        Node curr = merge(leftChild, rightChild);
        sum[v] = curr.sum, prefix[v] = curr.prefix, suffix[v] = curr.suffix, largest[v] = curr.largest;
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if(r <= tl || tr <= l) return {0, 0, 0, 0};
        if(l <= tl && tr <= r) return { sum[v], prefix[v], suffix[v], largest[v] };
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm, tr, l, r));
    }

    void build(vector<int>& a) { build(1, 0, n, a); }
    int query(int l, int r) { Node node = query(1, 0, n, l, r); return node.largest; }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n); cin >> nums;

    SegMax seg(n);
    seg.build(nums);

    for(int j = 0; j < q; ++j) {
        int a, b; cin >> a >> b;
        cout << seg.query(a - 1, b) << '\n';
    }
}
