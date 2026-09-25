#include "cp.h"

void solve() {
    // compute floor(log2(v)) for all v
    const int MAXN = 2e5 + 5;
    int lg[MAXN]; lg[1] = 0;
    for(int i = 2; i < MAXN; ++i) lg[i] = lg[i/2] + 1;

    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;

    // init sparse table
    int LOG = lg[n] + 1;
    vector<vector<int>> sparse(LOG, vector<int>(n, INT_MAX));
    copy(a.begin(), a.end(), sparse[0].begin());

    for(int j = 1; j < LOG; ++j) {
        for(int i = 0; i + (1 << j) <= n; ++i) {
            int left = sparse[j-1][i];
            int right = sparse[j-1][i + (1 << (j-1))];
            sparse[j][i] = min(left, right);
        }
    }

    for(int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        int l = a - 1, r = b - 1;

        int k = lg[r - l + 1];
        int leftCov = sparse[k][l], rightCov = sparse[k][r - (1 << k) + 1];
        cout << min(leftCov, rightCov) << endl;
    }
}
