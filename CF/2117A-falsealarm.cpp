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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int i;
        vi doors(n);
        for (i = 0; i < n; i++)
        {
            cin >> doors[i];
        }
        int ff, fl;
        for (i = 0; i < n; i++)
        {
            if (doors[i] == 1)
            {
                ff = i;
                break;
            }
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (doors[i] == 1)
            {
                fl = i;
                break;
            }
        }
        if (fl - ff < x)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}