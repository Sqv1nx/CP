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
   - GCD/LCM: __gcd(a, b) | lcm = a / __gcd(a, b) * b
   - Ceil Div: (a + b - 1) / b  // for positive a, b
   - Power of 2 check: (n && !(n & (n - 1)))
   - i-th bit: (n >> i) & 1  | Set: n |= (1LL << i)  | Clear: n &= ~(1LL << i)
   - Dedup sorted vector: v.erase(unique(all(v)), v.end())
   - Sort by 2nd elem: sort(all(v), [](auto &a, auto &b){ return a.ss < b.ss; })
   - 2D Grid Init: vector<vi> grid(n, vi(m, 0))
   - Max/Min in range: *max_element(all(v)) | *min_element(all(v))
   - Index of max: max_element(all(v)) - v.begin()
   - Next Permutation: next_permutation(all(v)) // sort first for full cycle
   - Count Digits: to_string(n).size()
   - Coordinate Compression: auto vals = compress(v); v[i] -> new rank
   --------------------------------------------------- */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// --- PBDS ---
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): iterator to k-th smallest (0-indexed)
// order_of_key(x): count of elements strictly smaller than x

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
using vb = vector<bool>;

// --- Macros ---
#define f(i, s, e) for (ll i = (s); i < (e); i++)
#define rf(i, e, s) for (ll i = (e) - 1; i >= (s); i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
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

// --- Graph / Tree / DSU ---
using graph = vector<vi>;
using wgraph = vector<vpi>; // adjacency list of {neighbor, weight}

struct DSU
{
    vi par, siz;
    int comps;
    DSU(int n) : par(n), siz(n, 1), comps(n) { iota(all(par), 0); }
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        comps--;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

vi bfs(int src, graph &adj)
{
    vi dist(adj.size(), -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return dist;
}

void dfs(int src, graph &adj, vi &vis)
{
    stack<int> st;
    st.push(src);
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v : adj[u])
            if (!vis[v])
                st.push(v);
    }
}

vll dijkstra(int src, wgraph &adj)
{
    vll dist(adj.size(), INF);
    priority_queue<pll, vpll, greater<pll>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// --- Coordinate Compression ---
template <typename T>
vector<T> compress(vector<T> &a)
{
    vector<T> vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for (auto &x : a)
        x = lower_bound(all(vals), x) - vals.begin() + 1; // 1-indexed
    return vals;
}
template <typename T>
T decompress(int rank, const vector<T> &vals) { return vals[rank - 1]; }

// --- Subsets (Bitmask + Backtracking) ---
// Bitmask: iterate all 2^n subsets via bit i of mask => include element i
void allSubsetsBitmask(int n)
{
    for (int b = 0; b < (1 << n); b++)
    {
        vi subset;
        for (int i = 0; i < n; i++)
            if (b & (1 << i))
                subset.pb(i);
        // process subset
    }
}
// Backtracking: include/exclude recursion, generates all 2^n subsets
void subsetsBacktrack(int i, int n, vi &cur, vector<vi> &all)
{
    if (i == n)
    {
        all.pb(cur);
        return;
    }
    subsetsBacktrack(i + 1, n, cur, all); // exclude element i
    cur.pb(i);                            // include element i
    subsetsBacktrack(i + 1, n, cur, all);
    cur.pop_back(); // backtrack
}

// --- Fenwick Tree (BIT) ---
struct Fenwick
{
    int n;
    vll tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, ll delta)
    {
        for (; i <= n; i += i & (-i))
            tree[i] += delta;
    }
    ll query(int i)
    {
        ll s = 0;
        for (; i > 0; i -= i & (-i))
            s += tree[i];
        return s;
    }
    ll query(int l, int r) { return query(r) - query(l - 1); } // 1-indexed, inclusive
};

// --- Iterative Segment Tree (point update, range sum) ---
struct SegTree
{
    int n;
    vll tree;
    SegTree(int n) : n(n), tree(2 * n, 0) {}
    void update(int p, ll val)
    {
        for (tree[p += n] = val; p > 1; p >>= 1)
            tree[p >> 1] = tree[p] + tree[p ^ 1]; // change op for max/min
    }
    ll query(int l, int r)
    {               // inclusive, 0-indexed
        ll res = 0; // change identity for max/min
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += tree[l++];
            if (r & 1)
                res += tree[--r];
        }
        return res;
    }
};

// --- Lazy Segment Tree (range update, range sum) ---
struct LazySegTree
{
    int n;
    vll tree, lazy;
    LazySegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}
    void push(int node, int start, int end)
    {
        if (lazy[node] == 0)
            return;
        tree[node] += lazy[node] * (end - start + 1); // remove *(len) for max/min
        if (start != end)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void update(int node, int start, int end, int l, int r, ll val)
    {
        push(node, start, end);
        if (start > end || start > r || end < l)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // change to max/min
    }
    ll query(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (start > end || start > r || end < l)
            return 0; // 0 for sum, -INF/INF for max/min
        if (start >= l && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
    void update(int l, int r, ll val) { update(1, 0, n - 1, l, r, val); }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

// --- Double String Hashing ---
struct StringHash
{
    static inline const ll M1 = 1e9 + 9, M2 = 1e9 + 7;
    static inline ll B1 = 0, B2 = 0;
    static inline vll pw1{1}, pw2{1};
    vll h1, h2;
    StringHash(const str &s) : h1(s.size() + 1), h2(s.size() + 1)
    {
        if (B1 == 0)
        { // seed random bases once
            mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
            B1 = 300 + rng() % (M1 - 300), B2 = 300 + rng() % (M2 - 300);
        }
        while ((ll)pw1.size() <= (ll)s.size())
        {
            pw1.pb(pw1.back() * B1 % M1);
            pw2.pb(pw2.back() * B2 % M2);
        }
        f(i, 0, (ll)s.size())
        {
            h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
        }
    }
    pll get(int l, int r)
    { // inclusive, 0-indexed substring hash
        ll a = ((h1[r + 1] - h1[l] * pw1[r - l + 1]) % M1 + M1) % M1;
        ll b = ((h2[r + 1] - h2[l] * pw2[r - l + 1]) % M2 + M2) % M2;
        return {a, b};
    }
};

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
void search(ll y, vll &col, vll &diag1, vll &diag2, ll &cnt, vector<str> &board)
{
    if (y == 8)
    {
        cnt++;
        return;
    }
    f(x, 0, 8)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + 7] || board[y][x] == '*')
            continue;
        col[x] = 1;
        diag1[x + y] = 1;
        diag2[x - y + 7] = 1;
        search(y + 1, col, diag1, diag2, cnt, board);
        col[x] = 0;
        diag1[x + y] = 0;
        diag2[x - y + 7] = 0;
    }
}
void solve()
{
    vector<str> board(8);
    f(i, 0, 8)
    {
        cin >> board[i];
    }
    vll col(8, 0);
    vll diag1(15, 0);
    vll diag2(15, 0);
    ll cnt = 0;
    search(0, col, diag1, diag2, cnt, board);
    cout << cnt << '\n';
}

int main()
{
    fast_io;
    // sieve();
    // precompute_factorials();
    // precompute_fib();
    // setIO("problemname");
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}