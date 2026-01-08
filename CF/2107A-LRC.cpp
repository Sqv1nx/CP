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
        vector<pair<int, int>> num(n);
        int i;
        int maxx = 0;
        for (i = 0; i < n; i++)
        {
            cin >> num[i].first;
            maxx = max(maxx, num[i].first);
        }
        int counts = 0, countl = 0;
        i = 1;
        while (i<= maxx)
        {
            counts = 0;
            countl = 0;
            int j;
            for (j = 0; j < n; j++)
            {
                if ((num[j].first) % i == 0)
                {
                    counts++;
                    num[j].second = 1;
                }
                else
                {
                    countl++;
                    num[j].second = 0;
                }
            }
            if (counts != n && countl != n)
                break;

            i++;
        }
        if (counts != n && countl != n)
        {
            cout << "Yes" << '\n';
            for (i = 0; i < n; i++)
            {
                cout << num[i].second + 1 << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    return 0;
}