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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    ll root = (ll)sqrt((float)x);
    while (root > 0)
    {
        ll b = x / root;
        if (x == 1)
        {
            cout << 1 << ' ' << 1 << '\n';
            break;
        }
        if (b * root == x && b != root && gcd(b, root) == 1)
        {
            cout << root << ' ' << b << '\n';
            break;
        }
        else
        {
            root--;
        }
    }
    return 0;
}