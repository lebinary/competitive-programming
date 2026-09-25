#include "cp.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<char>> forest(n, vector<char>(n));
    for(int i = 0; i < n; ++i) cin >> forest[i];

    // 2D prefix
    vector<vector<long long>> prefix(n, vector<long long>(n, 0));
    for(int r = 0; r < n; ++r) {
        long long sum = 0;
        for(int c = 0; c < n; ++c) {
            if(r - 1 >= 0) prefix[r][c] = prefix[r-1][c];
            if(forest[r][c] == '*') sum += 1;
            prefix[r][c] += sum;
        }
    }

    for(int i = 0; i < q; ++i) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        long long topArea = y1 - 1 >= 0 ? prefix[y1-1][x2] : 0;
        long long leftArea = x1 - 1 >= 0 ? prefix[y2][x1-1] : 0;
        long long topLeftArea = y1 - 1 >= 0 && x1 - 1 >= 0 ? prefix[y1-1][x1-1] : 0;
        cout << prefix[y2][x2] - topArea - leftArea + topLeftArea << endl;
    }
}
