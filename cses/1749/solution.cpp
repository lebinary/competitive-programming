#include "cp.h"

struct Seg {
    int n; vector<int> t;
    Seg(int n) : n(n), t(4 * n) { build(1, 0, n); }

    void build(int v, int tl, int tr) {
        if(tr - tl == 1) { t[v] = 1; return; }
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm); build(2*v+1, tm, tr);
        t[v] = t[2*v] + t[2*v+1];
    }

    int descend(int v, int tl, int tr, int p) {
        if(tr - tl == 1) { t[v] = 0; return tl; }

        int tm = (tl + tr) / 2;
        int res;
        if(p <= t[2*v]) res = descend(2*v, tl, tm, p);
        else res = descend(2*v+1, tm, tr, p - t[2*v]);
        t[v] = t[2*v] + t[2*v+1];

        return res;
    }

    int descend(int p) { return descend(1, 0, n, p); }
};


/**

nums = [2 6 1 4 2]
p    = [3,1,3,1,1]


                [0, 5): 3
    [0,2): 1               [2, 5): 2
[0,1): 0 [1, 2): 1    [2,3): 0      [3, 5): 2
                                [3,4): 1    [4, 5): 1

 */

void solve() {
    int n; cin >> n;
    vector<int> nums(n); cin >> nums;
    vector<int> removes(n); cin >> removes;

    Seg tree(n);

    for(int p : removes) {
        int i = tree.descend(p);
        cout << nums[i] << ' ';
    }
    cout << endl;
}
