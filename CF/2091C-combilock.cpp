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
using namespace std;

// Type & Container Aliases
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using mii = map<int, int>;
using si = set<int>;
using msll = multiset<ll>;

// Macros
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// Constants
const ll MOD9 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

// Modular Arithmetic
ll mul(ll a, ll b, ll m = MOD9) { return ((a % m) * (b % m)) % m; }
ll add(ll a, ll b, ll m = MOD9) { return (a % m + b % m) % m; }
ll sub(ll a, ll b, ll m = MOD9) { return (a % m - b % m + m) % m; }
ll expo(ll a, ll b, ll m = MOD9)
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
ll modInverse(ll n, ll m = MOD9) { return expo(n, m - 2, m); }

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(str t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve()
{
    ll n;
    cin>>n;
    if (n % 2 == 0)
    {
        cout << -1 << '\n';
    }
    else if(n==1)
    {
        cout<<1<<'\n';
    }
    else 
    {
        f(i, 4, n)
        {
            cout << i << ' ';
            i++;
        }
        cout << 1 << ' ' << 3 << ' ';
        f(i, 5, n + 1)
        {
            cout << i << ' ';
            i++;
        }
        cout << 2 << ' ';
        cout<<'\n';
    }
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}