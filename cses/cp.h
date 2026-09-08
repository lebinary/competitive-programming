#include <bits/stdc++.h>
using namespace std;

// CSES-specific notes:
//  - Almost no CSES problem has a leading test-case count T. Read input directly.
//  - Answers routinely overflow 32-bit, so `int` is aliased to long long below.
//  - Many problems ask for the answer modulo 1e9+7; MOD and the mod helpers are
//    here for those.
//  - Input can be large (2e5..1e6 numbers). sync_with_stdio(false) is required;
//    prefer '\n' over endl.

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define unq(v) v.erase(unique(v.begin(), v.end()), v.end()) // sort first

const int MOD = 1e9 + 7;
const int INF = (int)4e18;

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

int power(int b, int e, int m = MOD) {
    int r = 1 % m;
    b %= m;
    while (e > 0) {
        if (e & 1)
            r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

// ============================ DEBUG (only with -DLOCAL) =====================
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v)                                                             \
    do {                                                                      \
        cerr << #v << " = ";                                                  \
        for (auto _x : (v))                                                   \
            cerr << _x << " ";                                                \
        cerr << endl;                                                         \
    } while (0)
#define debugp(p)                                                             \
    cerr << #p << " = (" << (p).first << ", " << (p).second << ")" << endl
#else
#define debug(x)
#define debugv(v)
#define debugp(p)
#endif
// ============================================================================

// ====================== read/write vectors and pairs directly ===============
template <typename A, typename B> istream &operator>>(istream &in, pair<A, B> &a) {
    return in >> a.first >> a.second;
}
template <typename A> istream &operator>>(istream &in, vector<A> &a) {
    for (auto &x : a)
        in >> x;
    return in;
}
template <typename A, typename B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
    return out << a.first << ' ' << a.second;
}
template <typename A> ostream &operator<<(ostream &out, const vector<A> &a) {
    for (int i = 0; i < (int)a.size(); i++)
        out << a[i] << " \n"[i + 1 == (int)a.size()];
    return out;
}
// ============================================================================

// Defined by each problem's solution.cpp.
void solve();

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    // Only redirect if input.txt exists, so the binary still reads stdin
    // when you run it by hand.
    if (freopen("input.txt", "r", stdin) == nullptr)
        cerr << "[local] no input.txt, reading stdin\n";
#endif

    // CSES: single test case. If a problem does start with T, uncomment:
    // int T; cin >> T; while (T--) solve();
    solve();

    return 0;
}
