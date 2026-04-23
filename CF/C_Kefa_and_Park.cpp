/****************************************************
 * /----------------------------------------------\ *
 * |             Code by sqv1nx_                  | *
 * \----------------------------------------------/ *
 ****************************************************/

/* CHEAT SHEET --------------------------------------
   - Index = lower_bound(all(v), x) - v.begin()
   - First element > x  = *upper_bound(all(v), x)
   - Last element <= x = *(--upper_bound(all(v), x))
   - Multiset Delete: s.erase(s.find(x)) // One instance
   - PQ Min-Heap: priority_queue<int, vi, greater<int>>
   - Bit Count: __builtin_popcountll(n) // Count 1s
   - nCr: (n! / (r! * (n-r)!)) % mod // Use modInverse
   --------------------------------------------------- */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// --- PBDS ---
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// --- Type Aliases ---
using ll = long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpll = vector<pll>;

// --- Macros ---
#define f(i, s, e) for (ll i = (s); i < (e); i++)
#define rf(i, e, s) for (ll i = (e) - 1; i >= (s); i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// --- Constants ---
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

// --- Math & Modular Arithmetic ---
ll mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; }
ll add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return (a % m - b % m + m) % m; }
ll expo(ll a, ll b, ll m = MOD)
{
    ll res = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return res;
}
ll modInverse(ll n, ll m = MOD) { return expo(n, m - 2, m); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }

ll fact[N], inv_fact[N];
void precompute_factorials(ll m = MOD)
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i, m);
    inv_fact[N - 1] = modInverse(fact[N - 1], m);
    for (int i = N - 2; i >= 0; i--)
        inv_fact[i] = mul(inv_fact[i + 1], i + 1, m);
}
ll ncr(ll n, ll r, ll m = MOD)
{
    if (n < r || r < 0)
        return 0;
    return mul(fact[n], mul(inv_fact[r], inv_fact[n - r], m), m);
}

// --- File IO ---
void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// --- Debugging ---
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void __print(ll t) { cerr << t; }
void __print(int t) { cerr << t; }
void __print(str t) { cerr << '"' << t << '"'; }
void __print(char t) { cerr << "'" << t << "'"; }
void __print(bool t) { cerr << (t ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &p)
{
    cerr << "{";
    __print(p.ff);
    cerr << ",";
    __print(p.ss);
    cerr << "}";
}
template <typename T>
void __print(const T &v)
{
    int f = 0;
    cerr << "{";
    for (auto &i : v)
    {
        cerr << (f++ ? "," : "");
        __print(i);
    }
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

void addegde(map<ll, vll> &adj__, ll &f, ll &t)
{
    adj__[f];
    adj__[t];
    adj__[f].pb(t);
    adj__[t].pb(f);
}
void addegde_(map<ll, vll> &adj__, ll &f, ll &t)
{
    adj__[f];
    adj__[t];
    adj__[f].pb(t);
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, vll> adj;
    map<ll, vll> adj_;
    map<ll, ll> par;
    vll cats(n + 1);
    vll tc(n + 1);
    f(i, 1, n + 1)
    {
        cin >> cats[i];
    }
    tc[1] = cats[1];
    ll x, y;
    while (cin >> x >> y)
    {
        addegde(adj, x, y);
    }

    vll leaf;
    vll dist(n + 1);
    dist[1] = 0;
    vector<bool> pos(n + 1, true);
    queue<ll> q;
    q.push(1);
    set<ll> v;
    v.insert(1);
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();
        // v.insert(k);
        for (auto ele : adj[k])
        {
            if (v.find(ele) == v.end())
            {
                v.insert(ele);
                par[ele] = k;
                dist[ele] = dist[k] + 1;
                q.push(ele);
                addegde_(adj_, k, ele);
            }
        }
    }
    f(i, 1, n + 1)
    {
        if (adj_[i].size() == 0)
        {
            leaf.pb(i);
        }
    }

    set<ll> vi;
    vi.insert(1);
    q.push(1);
    vll order;
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();
        order.pb(k);
        for (auto ele : adj_[k])
        {
            if (vi.find(ele) == vi.end())
            {
                vi.insert(ele);
                if (cats[ele] == 1)
                    tc[ele] = cats[ele] + tc[par[ele]];
                else
                {
                    tc[ele] = 0;
                }
                q.push(ele);
            }
        }
    }
    for (auto ele : order)
    {
        if (tc[ele] > m || pos[par[ele]] == false)
        {
            pos[ele] = false;
        }
    }
    ll ans = 0;
    for (auto ele : leaf)
    {
        if (pos[ele] == true)
        {
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    fast_io;
    // precompute_factorials();
    // setIO("problemname");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}