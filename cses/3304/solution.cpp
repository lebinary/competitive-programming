#include "cp.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> height(n); cin >> height;

    vector<vector<int>> queries;
    for(int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        queries.push_back({a-1, b-1, i});
    }
    sort(all(queries));

    vector<int> view;
    vector<int> res(q);
    int i = q - 1;

    // O((n + q)logn)
    for(int a = n-1; a >= 0; --a) {
        while(!view.empty() && height[view.back()] <= height[a]) view.pop_back();
        view.push_back(a);

        while(i >= 0 && a == queries[i][0]) {
            int b = lower_bound(all(view), queries[i][1], greater<int>()) - view.begin();
            res[queries[i][2]] = view.size() - b;
            i--;
        }
    }

    for(int r : res) cout << r << '\n';
}
