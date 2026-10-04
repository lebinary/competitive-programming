#include "cp.h"

struct Fenwick {
    int n; vector<int> bit;
    Fenwick(int n): n(n), bit(n + 1) {}

    void inc(int i) { for(; i <= n; i += i & -i) bit[i] += 1; }

    int sum(int i) { int s = 0; for(; i > 0; i -= i & -i) s += bit[i]; return s; }
    int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n); cin >> nums;

    vector<vector<int>> values(n);
    for(int i = 0; i < n; ++i) {
        values[i] = {nums[i], i};
    }
    sort(all(values));

    vector<vector<int>> subqueries; // size 2 * q
    for(int j = 0; j < q; ++j) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        subqueries.push_back({d, a, b, 1, j});
        subqueries.push_back({c - 1, a, b, -1, j});
    }
    sort(all(subqueries));

    vector<int> res(q);
    Fenwick bit(n);

    int i = 0;
    for(auto& query : subqueries) {
        int v = query[0], a = query[1], b = query[2], sign = query[3], j = query[4];

        while(i < n && values[i][0] <= v) {
            bit.inc(values[i][1] + 1);
            i++;
        }

        res[j] += sign * bit.sum(a, b);
    }

    for(int r : res) cout << r << '\n';
}
