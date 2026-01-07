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
        vi ele(n);
        int i, same = 1;
        cin >> ele[0];
        for (i = 1; i < n; i++)
        {
            cin >> ele[i];
            if (ele[i] == ele[i - 1])
            {
                same++;
            }
        }
        if (same == n)
        {
            cout << "YES" << '\n';
        }
        else if (n % 2 == 1)
        {
            vi diff(n - 1);
            for (i = 0; i < n - 1; i++)
            {
                diff[i] = abs(ele[i + 1] - ele[i]);
            }
            same = 1;
            for (i = 1; i < n - 1; i++)
            {
                if (diff[i] == diff[i - 1])
                {
                    same++;
                }
            }
            if (same == n - 1)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}