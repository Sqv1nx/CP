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
        string shift;
        cin >> shift;
        int zc = 0;
        int i;
        int ans = 0;

        if (shift[0] == '0')
        {
            zc++;
        }
        ans = max(ans, zc);
        for (i = 1; i < n; i++)
        {
            if (shift[i] == '0' && shift[i - 1] == '0')
            {
                zc++;
            }
            else
            {
                if (shift[i] == '1')
                    zc = 0;
                else
                    zc = 1;
            }
            ans = max(ans, zc);
        }

        if (shift[0] == '0')
        {
            zc++;
        }
        ans = max(ans, zc);
        for (i = 1; i < n; i++)
        {
            if (shift[i] == '0' && shift[i - 1] == '0')
            {
                zc++;
            }
            else
            {
                if (shift[i] == '1')
                    zc = 0;
                else
                    zc = 1;
            }
            ans = max(ans, zc);
        }
       
        cout << ans << '\n';
    }
    return 0;
}