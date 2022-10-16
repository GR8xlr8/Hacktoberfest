#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1000000000;
const ll LINF = 1000000000000000000;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

#define _sel(_1, _2, x, ...) x
#define repn(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, ...) _sel(__VA_ARGS__, reps, repn)(i, __VA_ARGS__)
#define reppn(i, n) for (ll i = 1; i <= (n); i++)
#define repps(i, a, b) for (ll i = (a); i <= (b); i++)
#define repp(i, ...) _sel(__VA_ARGS__, repps, reppn)(i, __VA_ARGS__)
#define rrepn(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rreps(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define rrep(i, ...) _sel(__VA_ARGS__, rreps, rrepn)(i, __VA_ARGS__)
#define rreppn(i, n) for (ll i = (n); i >= 1; i--)
#define rrepps(i, a, b) for (ll i = (b); i >= (a); i--)
#define rrepp(i, ...) _sel(__VA_ARGS__, rrepps, rreppn)(i, __VA_ARGS__)

#define pb push_back
#define fi first
#define se second
#define rng(v) (v).begin(), (v).end()
#define rrng(v) (v).rbegin(), (v).rend()
#define siz(x) ll((x).size())
#define pow2(x) (1ll << (x))
#define bit(x, n) ((x) >> (n) & 1)
#define prt(x) cout << (x) << endl
#define dbg(x) dbgn(#x, x)
#define dec() cout << fixed << setprecision(15)

template<typename T, typename U> inline bool umax(T& m, U x) { if (m < x) { m = x; return true; } return false; }
template<typename T, typename U> inline bool umin(T& m, U x) { if (m > x) { m = x; return true; } return false; }
template<typename T> inline void errv(T& v) { for (auto x : v) cerr << x << " "; cerr << endl; }
inline void errv(vb& v) { for (auto x : v) cerr << (x ? 1 : 0) << " "; cerr << endl; }
template<typename T> inline void dbgn(string n, T x) { cerr << n << ": " << x << endl; }
template<typename T> inline void dbgn(string n, vector<T>& v) { cerr << n << ": "; errv(v); }
template<typename T> inline void dbgn(string n, vv<T>& m) { cerr << n << ":" << endl; for (auto& v : m) errv(v); }

struct UnionFind {
    vi p;
    UnionFind(ll n): p(n, -1) { }
    ll root(ll x) { if (p[x] < 0) return x; else return p[x] = root(p[x]); }
    ll size(ll x) { return -p[root(x)]; }
    void unite(ll x, ll y) {
        ll rx = root(x), ry = root(y);
        if (rx == ry) return; if (p[rx] > p[ry]) swap(rx, ry);
        p[rx] += p[ry]; p[ry] = rx;
    }
};

//ll MOD = 1000000007;
ll MOD = 998244353;

struct mint {
    ll x;
    mint(ll a = 0): x((a + MOD) % MOD) { }
    mint operator+(mint a) { return mint(*this) += a; }
    mint operator-(mint a) { return mint(*this) -= a; }
    mint operator*(mint a) { return mint(*this) *= a; }
    mint operator/(mint a) { return mint(*this) /= a; }
    mint& operator+=(mint a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
    mint& operator-=(mint a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
    mint& operator*=(mint a) { (x *= a.x) %= MOD; return *this; }
    mint& operator/=(mint a) { return *this *= a.inv(); }
    mint pow(ll t) { mint a = x, ret = 1; while (t) { if (t & 1) ret *= a; a *= a; t >>= 1; } return ret; }
    mint inv() { return pow(MOD - 2); }
    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, mint& a) { return os << a.x; }
};


int main() {
    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i) {
        double r1 , r2;
        cin >> r1 >> r2;
        double eq = r1 + r2;
        int n;
        cin >> n;
        double ans1 = 0, ans2 = 0;
        vector<double>v1, v2;
        for (int i = 0; i < n; ++i) {
            double x, y;
            cin >> x >> y;
            double ans = sqrt(pow(x, 2) + pow(y, 2));


            if (ans <= eq)
            {
                v1.push_back(ans);
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            double x, y;
            cin >> x >> y;
            double ans = sqrt(pow(x, 2) + pow(y, 2));
            if (ans <= eq)
            {

                v2.push_back(ans);

            }
        }
        for (int i = 0; i < v1.size(); i++)
        {
            int stop = true;
            for (int j = 0; j < v2.size(); j++)
            {
                if (v2[j] < v1[i]) {
                    stop = false;
                    break;
                }
            }
            if (stop)
                ans1++;
        }
        for (int i = 0; i < v2.size(); i++)
        {
            int stop = true;
            for (int j = 0; j < v1.size(); j++)
            {
                if (v1[j] < v2[i]) {
                    stop = false;
                    break;
                }
            }
            if (stop)
                ans2++;
        }
        cout << "Case #" << i << ": " << ans1 << " " << ans2 << endl;
    }
}
