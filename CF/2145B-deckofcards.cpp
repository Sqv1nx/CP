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
        int n, k;
        cin >> n >> k;
        string order;
        cin >> order;
        int i;
        sort(order.begin(), order.end());
        if (n != k)
        {
            vector<char> ans(n, '+');
            int f = 0, b = n - 1;
            for (i = 0; i < n && k--; i++)
            {
                if (order[i] == '0')
                {
                    ans[f] = '-';
                    f++;
                }
                else if (order[i] == '1')
                {
                    ans[b] = '-';
                    b--;
                }
                else if (order[i] == '2')
                {
                    ans[f] = '?';
                    ans[b] = '?';
                    f++;
                    b--;
                }
            }
            for (i = 0; i < n; i++)
            {
                cout << ans[i];
            }
        }
        else
        {
            vector<char> ans(n, '-');

            for (i = 0; i < n; i++)
            {
                cout << ans[i];
            }
        }
        cout << '\n';
    }
    return 0;
}