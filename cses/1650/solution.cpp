#include "cp.h"

void solve() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    cin >> a;

    vector<long long> prefixXor(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum ^= a[i];
        prefixXor[i] = sum;
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        int res = prefixXor[b - 1] ^ (a - 2 >= 0 ? prefixXor[a - 2] : 0);
        cout << res << endl;
    }
}
