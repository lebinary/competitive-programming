#include "cp.h"

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    cin >> a;

    vector<long long> prefix(n);
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += a[i];
        prefix[i] = sum;
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b-1] - (a - 2 >= 0 ? prefix[a-2] : 0) << endl;
    }
}
