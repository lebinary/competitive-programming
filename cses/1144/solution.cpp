#include "cp.h"

struct Fenwick {
    int n; vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1) {}
    Fenwick(vector<int>& a) : Fenwick(a.size()) {
        for(int i = 1; i <= n; ++i) {
            bit[i] += a[i - 1];
            int j = i + (i & -i);
            if(j <= n) bit[j] += bit[i];
        }
    }

    void update(int i, int delta) { for(; i <= n; i += i & -i) bit[i] += delta; } // 1-based

    int prefixSum(int i) const { int s = 0; for(; i > 0; i -= i & -i) s += bit[i]; return s; }
    int query(int l, int r) const { return prefixSum(r) - prefixSum(l - 1); }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> salary(n); cin >> salary;

    // pre-processed
    vector<int> values = salary;
    vector<tuple<char, int, int>> ops(q);
    for(auto& [t, x, y] : ops) {
        cin >> t >> x >> y;
        if(t == '!') values.push_back(y);
    }

    srt(values); unq(values);

    // process the ops
    vector<int> freq(sz(values));
    for(int s : salary) {
        int freqIdx = lower_bound(all(values), s) - values.begin();
        freq[freqIdx]++;
    }

    Fenwick fwt(freq);

    for(auto& op : ops) {
        char type = get<0>(op);
        if(type == '!') {
            int k = get<1>(op), x = get<2>(op);
            int prevVal = salary[k - 1];
            salary[k - 1] = x;

            int prevValIdx = lower_bound(all(values), prevVal) - values.begin() + 1; // 1-based
            fwt.update(prevValIdx, -1);
            int newValIdx = lower_bound(all(values), x) - values.begin() + 1;
            fwt.update(newValIdx, 1);
        } else {
            int a = get<1>(op), b = get<2>(op);
            int l = lower_bound(all(values), a) - values.begin() + 1; // 1-based
            int r = upper_bound(all(values), b) - values.begin();
            cout << fwt.query(l, r) << '\n';
        }
    }
}
