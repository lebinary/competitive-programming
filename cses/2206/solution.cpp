#include "cp.h"

/**
For any k: min_price = min(min_left_pizzeria, min_right_pizzeria)
    min_left_pizzeria (a <= k): p_a + |k - a| = (p_a - a) + k
        => minimize (p_a - a) in prefix [1, k]

    min_left_pizzeria (k <= a): p_a + |a - k| = (p_a + a) - k
        => minimize (p_a + a) in postfix [k, n]
 */

struct SegMin {
    int n; vector<int> t;
    SegMin(int n) : n(n), t(2*n) {}
    SegMin(vector<int>& a) : SegMin(a.size()) {
        copy(all(a), t.begin() + n);
        for(int i = n - 1; i > 0; --i) t[i] = min(t[2*i], t[2*i+1]);
    }
    void update(int i, int x) {
        for(t[i += n] = x; i >>= 1; ) t[i] = min(t[2*i], t[2*i+1]);
    }
    int query(int l, int r) {
        int res = INF;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = min(res, t[l++]);
            if(r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> prices(n); cin >> prices;

    vector<int> forward(n);
    for(int i = 0; i < n; ++i) forward[i] = prices[i] - i;
    SegMin prefix(forward);

    reverse(all(prices));
    vector<int> backward(n);
    for(int i = 0; i < n; ++i) backward[i] = prices[i] + (n - 1 - i);
    SegMin suffix(backward);

    for(int i = 0; i < q; ++i) {
        int type; cin >> type;

        if(type == 1) {
            int k, x; cin >> k >> x;
            prefix.update(k - 1, x - (k - 1));
            suffix.update(n - k, x + (k - 1));
        } else {
            int k; cin >> k;
            int leftBest = prefix.query(0, k) + (k - 1), rightBest = suffix.query(0, n - k) - (k - 1);
            cout << min(leftBest, rightBest) << '\n';
        }
    }
}
