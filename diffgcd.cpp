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
        int n, a, b;
        cin >> n >> a >> b;
        vi arr(n + 1);
        int i;
        bool toot = false;
        for (i = 1; i <= n && !toot; i++)
        {
            int modu = a % i;
            if (modu == 0)
            {
                arr[i] = a;
            }
            else
            {
                modu = i - modu;
                if ((a + modu) > b)
                {
                    toot = true;
                }
                else
                {
                    arr[i] = a + modu;
                }
            }
        }
        if (!toot)
        {
            cout << "YES" << '\n';
            for (i = 1; i <= n; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}