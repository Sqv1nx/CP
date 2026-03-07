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
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Constants
const ll MOD9 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

// Modular Arithmetic
ll mul(ll a, ll b, ll m = MOD9) { return ((a % m) * (b % m)) % m; }
ll add(ll a, ll b, ll m = MOD9) { return (a % m + b % m) % m; }
ll sub(ll a, ll b, ll m = MOD9) { return (a % m - b % m + m) % m; }
ll expo(ll a, ll b, ll m = MOD9) { ll res = 1; a %= m; while (b > 0) { if (b & 1) res = mul(res, a, m); a = mul(a, a, m); b >>= 1; } return res; }
ll modInverse(ll n, ll m = MOD9) { return expo(n, m - 2, m); }

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(str t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve(vector<int> res) {
    ll n,m;
    cin>>n>>m;
    ll alice=0;
    ll bob=0;
    map<int,ll> a;
    f(i,0,n)
    {
        int x;
        cin>>x;
        if(binary_search(all(res),x))
        {
            a[x]++;
        }
        else if(x==1)
        {
            a[x]++;
            alice=m;
        }
    }
    int arr
    map<int,ll> bp;
    
    f(i,0,m)
    {
        int x;
        cin>>x;
        if(binary_search(all(res),x))
        {
            bp[x]++;
            bob++;
        }
        else
        {
            bool mila=false;
            if(mila || x==1)
            alice++;
            else
            {
                bob++;
            }
        }
    }
    if(alice>=bob)
    cout<<"Alice"<<'\n';
    else
    cout<<"Bob"<<'\n';
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    vector<bool> prime(1e6, true);
    for (int p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (int i = p * p; i <= 1e6; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= 1e6; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    while (t--) {
        solve(res);
    }
    return 0;
}