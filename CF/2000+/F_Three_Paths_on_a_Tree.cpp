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
   - Primes: is_prime[x] (check) | primes[i] (get i-th)
   -USE MULTI BFS FOR NO TLE;
   
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

// --- Number Theory / Sieve ---
bool is_prime[N];
vi primes;
void sieve()
{
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < N; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i < N; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < N; p++)
    {
        if (is_prime[p])
            primes.pb(p);
    }
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
void addedge(vector<vll> &adj, ll a, ll b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}
void deledge(vector<vll> &adj, ll a, ll b)
{
    f(i, 0, adj[a].size())
    {
        if (adj[a][i] == b)
        {
            adj[a][i] = 0;
            break;
        }
    }
}
void solve()
{
    // if this works idk how i fail div2 B
    // thanks to mr nepali mishra;
    ll n;
    cin >> n;
    vector<vll> adj(n + 1);
    f(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        addedge(adj, a, b);
    }
    // bfs 1
    vll d1(n + 1);
    vector<bool> v1(n + 1, false);
    queue<ll> q;
    ll source = 1;
    d1[source] = 0;
    q.push(source);
    v1[source] = true;
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();
        for (auto x : adj[k])
        {
            if (!v1[x])
            {
                q.push(x);
                v1[x] = true;
                d1[x] = d1[k] + 1;
            }
        }
    }
    ll dm1 = 0;
    f(i, 1, n + 1)
    {
        if (d1[i] > dm1)
        {
            dm1 = d1[i];
            source = i;
        }
    }
    // bfs2
    vector<bool> v2(n + 1, false);
    vll d(n + 1), p(n + 1);
    p[source] = 0;
    d[source] = 0;
    q.push(source);
    v2[source] = true;
    while (!q.empty())
    {
        ll k = q.front();
        q.pop();
        for (auto x : adj[k])
        {
            if (!v2[x])
            {
                q.push(x);
                v2[x] = true;
                p[x] = k;
                d[x] = d[k] + 1;
            }
        }
    }
    ll dm = 0;
    ll dest;
    f(i, 1, n + 1)
    {
        if (d[i] > dm)
        {
            dm = d[i];
            dest = i;
        }
    }
    // source and dest form diameter

    vll mid;
    ll temp = dest;
    while (temp != source)
    {
        mid.pb(temp);
        temp = p[temp];
    }
    mid.pb(source);
    // f(i, 0, mid.size())
    // {
    //     if (i < mid.size() - 1)
    //     {
    //         deledge(adj, mid[i], mid[i + 1]);
    //     }
    //     if (i > 0)
    //     {
    //         deledge(adj, mid[i], mid[i - 1]);
    //     }
    // }
    ll th;
    ll di = 0;
    // for (auto x : mid)
    // {
    //     if (x != source && x != dest)
    //     {
    //         vll dis(n + 1, -1);
    //         vector<bool> v(n+1,false);
    //         queue<ll> qu;
    //         dis[x] = 0;
    //         qu.push(x);
    //         v[x]=true;
    //         while (!qu.empty())
    //         {
    //             ll k = qu.front();
    //             qu.pop();
    //             for (auto t : adj[k])
    //             {
    //                 if (t != 0)
    //                 {
    //                     if (!v[t])
    //                     {
    //                         qu.push(t);
    //                         v[t]=true;
    //                         dis[t] = dis[k] + 1;
    //                     }
    //                 }
    //             }
    //         }
    //         f(i, 1, n + 1)
    //         {
    //             if (dis[i] >= di)
    //             {
    //                 di = dis[i];
    //                 th = i;
    //             }
    //         }
    //     }
    // }
    // mr mishra
    vector<bool> v(n + 1, false);
    vll dis(n + 1, -1);
    queue<ll> qu;
    for (auto x : mid)
    {
        dis[x] = 0;
        v[x] = true;
        qu.push(x);
    }
    while (!qu.empty())
    {
        ll k = qu.front();
        qu.pop();
        for (auto t : adj[k])
        {
            if (!v[t])
            {
                qu.push(t);
                v[t] = true;
                dis[t] = dis[k] + 1;
            }
        }
    }
    f(i, 1, n + 1)
    {
        if (i != source && i != dest)
        {
            if (dis[i] >= di)
            {
                di = dis[i];
                th = i;
            }
        }
    }
    cout << dm + di << '\n';
    cout << source << ' ' << dest << ' ' << th << '\n';
}

int main()
{
    fast_io;
    // sieve();
    // precompute_factorials();
    // setIO("problemname");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}