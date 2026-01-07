#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<int> vi;
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
    ull n, k;
    cin >> n >> k;
    k = k - 1;
    ull mid = (ull)(pow((double)2, (double)(n - 1)) - 1.0);
    if (k > mid)
        k = (ull)((ull)2 * mid - k);
    while (k != mid)
    {
        mid = mid / 2;
        n = n - 1;
        if (k > mid)
            k = (ull)((ull)2 * mid - k);
    }
    cout << n << '\n';
    return 0;
}
