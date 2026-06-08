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
   - Fibonacci: fib[i] (O(1) precomputed) | fib_fast(n).ff (O(log n))
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

ll fib[N];
void precompute_fib(ll m = MOD)
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; i++)
        fib[i] = add(fib[i - 1], fib[i - 2], m);
}

pll fib_fast(ll n, ll m = MOD)
{ // Returns {F(n), F(n+1)} in O(log n)
    if (n == 0)
        return {0, 1};
    auto p = fib_fast(n >> 1, m);
    ll c = mul(p.ff, sub(mul(2, p.ss, m), p.ff, m), m);
    ll d = add(mul(p.ff, p.ff, m), mul(p.ss, p.ss, m), m);
    if (n & 1)
        return {d, add(c, d, m)};
    return {c, d};
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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll st;
    if (k == 1)
    {
        cout << n%MOD << '\n';
    }
    else
    {
        ll a = 1;
        ll b = 1;
        f(i, 3, 6 * k + 1)
        {
            ll c = (a%k+ b%k) % k;
            if (c == 0)
            {
                st = i;
                break;
            }
            a=b;
            b=c;
        }
        cout << ((st%MOD) * (n%MOD)) % MOD << '\n'; 
    }
}

int main()
{
    fast_io;
    // sieve();
    // precompute_factorials();
    precompute_fib();
    // setIO("problemname");
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}