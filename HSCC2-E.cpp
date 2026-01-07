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
    if (k > n)
    {
        cout << "NO" << '\n';
    }
    else
    {
        bool p2 = false;
        bool p3 = false;
        int tmp = n;
        int powe = 0;
        while (tmp != 1)
        {
            tmp = tmp / 2;
            powe++;
        }
        tmp = pow(2, powe);
        if (tmp == n)
        {
            p2 = true;
        }
        if (tmp + 1 == n)
        {
            p3 = true;
        }
        if (k == 1 && p2)
        {
            cout << "YES" << '\n';
            cout << n << '\n';
        }
        else if (k != 1)
        {
            if (k == 2 && !p3)
            {
                cout << "NO";
            }
            else
            {
                vi ans(k);
                int cnt = 0;
                cout << "YES" << '\n';
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
                for (i = 0; i < k; i++)
                {
                    cout << ans[i] << ' ';
                }
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}