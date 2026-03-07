#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<int, int> pi;
#define REP(i, a, b) for (i = a; i < b; i++)
#define REPR(i, a, b) for (i = a; i > b; i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair

// variable madness take break could do btter nice tutorial   524 C masha
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll no, mo, ni, mi;
        cin >> no >> mo;
        ll w, bl, wi1, wi2, bli1, bli2;
        w = ((no + 1) / 2) * ((mo + 1) / 2) + (no / 2) * (mo / 2);
        bl = mo * no - w;

        ll a, b, c, d, p, q, r, s, l, m, n, o;
        cin >> a >> b >> c >> d;
        cin >> p >> q >> r >> s;

        if ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1))
        {
            l = c - a + (ll)1;
            m = d - b + (ll)1;
            n = 1;
            o = 1;
            ni = l - n + (ll)1;
            mi = m - o + (ll)1;
            wi1 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
            bli1 = ni * mi - wi1;
            bl = bl - bli1;
            w = w + bli1;
        }
        else
        {
            l = c - a + (ll)1;
            m = d - b + (ll)1;
            n = 1;
            o = 1;
            ni = l - n + (ll)1;
            mi = m - o + (ll)1;
            bli1 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
            wi1 = ni * mi - bli1;
            bl = bl - bli1;
            w = w + bli1;
        }

        if ((p % 2 == 0 && q % 2 == 0) || (p % 2 == 1 && q % 2 == 1))
        {
            l = r - p + (ll)1;
            m = s - q + (ll)1;
            n = 1;
            o = 1;
            ni = l - n + (ll)1;
            mi = m - o + (ll)1;
            wi2 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
            bli2 = ni * mi - wi2;
            w = w - wi2;
            bl = bl + wi2;
        }
        else
        {
            l = r - p + (ll)1;
            m = s - q + (ll)1;
            n = 1;
            o = 1;
            ni = l - n + (ll)1;
            mi = m - o + (ll)1;
            bli2 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
            wi2 = ni * mi - bli2;
            w = w - wi2;
            bl = bl + wi2;
        }

        p = max(a, p);
        q = max(b, q);
        r = min(c, r);
        s = min(d, s);
        if ((p <= r) && (q <= s))
        {
            if ((p % 2 == 0 && q % 2 == 0) || (p % 2 == 1 && q % 2 == 1))
            {
                r = r - p + (ll)1;
                s = s - q + (ll)1;
                p = 1;
                q = 1;
                ni = r - p + (ll)1;
                mi = s - q + (ll)1;
                wi2 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
                bli2 = ni * mi - wi2;
                w = w - bli2;
                bl = bl + bli2;
            }
            else
            {
                r = r - p + (ll)1;
                s = s - q + (ll)1;
                p = 1;
                q = 1;
                ni = r - p + (ll)1;
                mi = s - q + (ll)1;
                bli2 = ((ni + 1) / 2) * ((mi + 1) / 2) + (ni / 2) * (mi / 2);
                wi2 = ni * mi - bli2;
                w = w - bli2;
                bl = bl + bli2;
            }
            cout << w << ' ' << bl << '\n';
        }
        else
        {
            cout << w << ' ' << bl << '\n';
        }
    }
    return 0;
}




/// BTTTER 
// use fucions and dont repaet logic
//white ko kese bhi ginno chill hai


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll white(ll x, ll y) {
//     return ((x + 1) / 2) * ((y + 1) / 2) + (x / 2) * (y / 2);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         ll n, m, a, b, c, d, p, q, r, s;
//         cin >> n >> m;
//         ll W = white(n, m);
//         ll B = n * m - W;

//         cin >> a >> b >> c >> d;
//         ll x = c - a + 1, y = d - b + 1;
//         ll w1 = white(x, y), b1 = x * y - w1;

//         W += b1;
//         B -= b1;

//         cin >> p >> q >> r >> s;
//         x = r - p + 1;
//         y = s - q + 1;
//         ll w2 = white(x, y), b2 = x * y - w2;

//         W -= w2;
//         B += w2;

//         ll A = max(a, p), B2 = max(b, q);
//         ll C = min(c, r), D = min(d, s);

//         if (A <= C && B2 <= D) {
//             x = C - A + 1;
//             y = D - B2 + 1;
//             ll w3 = white(x, y), b3 = x * y - w3;

//             W -= b3;
//             B += b3;
//         }

//         cout << W << " " << B << "\n";
//     }

//     return 0;
// }
