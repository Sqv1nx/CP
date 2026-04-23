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

void solve()
{
    struct node
    {
        ll p;
        char data;
        ll l, r;
    };
    ll n;
    cin >> n;
    vector<node> tree(n + 1);
    string s;
    cin >> s;
    f(i, 1, n + 1)
    {
        tree[i].data = s[i - 1];
        ll x, y;
        cin >> x >> y;
        tree[i].l = x;
        tree[i].r = y;
    }
    f(i, 1, n + 1)
    {
        if (tree[i].l != 0)
            tree[tree[i].l].p = i;
        if (tree[i].r != 0)
            tree[tree[i].r].p = i;
    }
    vll changes(n + 1);
    vll leaf;
    f(i, 1, n + 1)
    {
        if (tree[i].l == 0 && tree[i].r == 0)
        {
            leaf.pb(i);
        }
    }
    changes[0] = 0;
    changes[1] = 0;
    queue<ll> q;
    q.push(1);
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();

        if (tree[k].l != 0)
        {
            if (tree[k].data == 'L')
            {
                changes[tree[k].l] = changes[k];
            }
            else
            {
                changes[tree[k].l] = changes[k] + 1;
            }
            q.push(tree[k].l);
        }
        if (tree[k].r != 0)
        {
            if (tree[k].data == 'R')
            {
                changes[tree[k].r] = changes[k];
            }
            else
            {
                changes[tree[k].r] = changes[k] + 1;
            }
            q.push(tree[k].r);
        }
        // cout<<"--"<<changes[i];
    }
    ll ans = 1e9;
    for (auto e : leaf)
    {
        ans = min(ans, changes[e]);
    }
    cout << ans << '\n';
}

int main()
{
    fast_io;
    // precompute_factorials();
    // setIO("problemname");
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}