#include "cp.h"

/**
    Thoughts: 2D counting problem - Scan y-dim while updating the x-dim. Query the count using fenwick
    Conditions:
        1. a <= i <= b
        2. pre[i] < a where pre[i] is last seen index j where nums[j] == nums[i]
 */

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) bit[i] += delta;
    }

    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    int sum(int a, int b) { return sum(b) - sum(a - 1); }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> nums(n); cin >> nums;

    // offline queries
    vector<vector<int>> queries(q);
    for (int j = 0; j < q; ++j) {
        int a, b; cin >> a >> b;
        queries[j] = {a, b, j};
    }
    sort(all(queries));

    // find pre[i] for all i
    vector<vector<int>> values(n), pre(n);
    for(int i = 0; i < n; ++i) values[i] = {nums[i], i};
    sort(all(values));
    for (int i = 0; i < n; ++i) {
        int currIdx = values[i][1];
        int preIdx = i - 1 < 0 || values[i-1][0] != values[i][0] ? -1 : values[i - 1][1];
        pre[i] = {preIdx, currIdx};
    };
    sort(all(pre));

    // 2D counting: scan queries, update elements that now becomes "unique" (second condition), query [a, b] from fenwick,
    Fenwick bit(n);

    int i = 0;
    vector<int> res(q);
    for (auto &query : queries) {
        int a = query[0], b = query[1], j = query[2];

        while (i < n && pre[i][0] < a - 1) {
            // fenwick update
            bit.update(pre[i][1] + 1, 1);
            i++;
        }

        // fenwick query
        res[j] = bit.sum(a, b);
    }

    for (int j = 0; j < q; ++j) cout << res[j] << '\n';
}
