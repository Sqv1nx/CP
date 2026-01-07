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
        int n;
        cin >> n;
        if (n == 1 || n == 3)
        {
            cout << -1 << '\n';
        }
        else
        {
            int i;
            for (i = n; i > (n + 1) / 2; i--)
            {
                cout << i << ' ';
            }
            for (i = 1; i <= (n + 1 )/2; i++)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}