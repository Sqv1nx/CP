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

    int n, k;
    cin >> n >> k;
    int mn = __builtin_popcount(n);
    if (k > n || k < mn)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        int tmp = n;
        int powe = 0;
        while (tmp != 1)
        {
            tmp = tmp / 2;
            powe++;
        }
        vi ans(k);
        int cnt = 0;
        int tt = pow(2, powe);
        while (n > 0)
        {
            if (n >= tt)
            {
                n = n - tt;
                ans[cnt] = tt;
                cnt++;
            }
            tt = tt / 2;
        }
        int i;
        i = cnt;
        cnt = 0;
        while (i < k)
        {
            int tmp = ans[cnt];
            if (tmp != 1)
            {
                ans[cnt] = tmp / 2;
                ans[i] = tmp - ans[cnt];
                i++;
            }
            else
            {
                cnt++;
            }
        }
        sort(ans.begin(),ans.end());
        for (i = 0; i < k; i++)
        {
            cout << ans[i] << ' ';
        }
    }
    return 0;
}