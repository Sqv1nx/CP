#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<ull> vi;
typedef vector<ull> vull;
typedef pair<ull, ull> pi;
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
    ull t;
    cin >> t;
    while (t--)
    {
        ull n, i;
        cin >> n;
        vi h(n);
        for (i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        if(n==1)
        {
            cout<<h[0]<<'\n';
            continue;
        }
        ull ans = 0;
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (h[i] > h[i + 1])
                {
                    ans += (ull)(h[i] - h[i + 1]);
                    h[i] = h[i + 1];
                }
            }
            else if (i == n - 1)
            {
                if (h[i] > h[i - 1])
                {
                    ans +=(ull)(h[i] - h[i - 1]);
                    h[i] = h[i - 1];
                }
            }
            else
            {
                if (h[i] > max(h[i - 1], h[i + 1]))
                {
                    ans += (ull)(h[i] - max(h[i - 1], h[i + 1]));
                    h[i] = max(h[i - 1], h[i + 1]);
                }
            }
        }
        ans += h[0];
        for (i = 1; i < n; i++)
        {
            if(h[i]>h[i-1])
            {
                ans+=(ull)(h[i]-h[i-1]);
            }
            else
            {
                ans+=(ull)(h[i-1]-h[i]);
            }
        }
        ans+=h[n-1];
        cout << ans << '\n';
    }
    return 0;
}