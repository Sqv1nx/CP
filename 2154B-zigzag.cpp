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
        int i;
        vi num(n);
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        int maxx = num[0];
        int ans = 0;

        for (i = 1; i < n; i++)
        {
            if (i % 2 == 1)
            {
                if (num[i] > num[i - 1])
                {
                    maxx = max(maxx, num[i]);
                }
                else
                {
                    num[i] = max(maxx, num[i]);
                    maxx = num[i];
                    if (num[i] > num[i - 1])
                    {
                        ;
                    }
                    else
                    {
                        ans = ans + num[i - 1] - num[i] + 1;
                    }
                }
            }
            else
            {
                if (num[i] < num[i - 1])
                {
                    ;
                }
                else
                {
                    num[i - 1] = maxx;
                    if (num[i] < num[i - 1])
                    {
                        ;
                    }
                    else
                    {
                        maxx = max(maxx, num[i]);
                        ans = ans + num[i] - num[i - 1] + 1;
                        num[i]=num[i-1]-1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}