#include "cp.h"

struct Seg {
    int n;
    vector<long long> t;

    Seg(vector<long long> &a) : n(a.size()), t(2 * n) {
        copy(a.begin(), a.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] + t[2 * i + 1];
    }

    void update(int i, long long v) {
        for (t[i += n] = v; i >>= 1;) t[i] = t[2 * i] + t[2 * i + 1];
    }

    long long query(int l, int r) {
        long long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

void solve() {
    // Read input and write your solution here.
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    cin >> a;

    Seg segTree(a);

    for (int i = 0; i < q; ++i) {
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 1) segTree.update(a - 1, b);
        else cout << segTree.query(a - 1, b) << endl;
    }
}
