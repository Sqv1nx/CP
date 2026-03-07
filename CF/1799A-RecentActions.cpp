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

        int n, m;
        cin >> n >> m;
        int count = 0;
        int i = 0;
        int counter = n;
        vi steps(m);
        vi tem(n + 1);
        vi distinct(1e5);

        for (i = 1; i <= n; i++)
        {
            distinct[i] = 1;
            tem[i] = -1;
        }

        for (i = 0; i < m; i++)
        {
            cin >> steps[i];
        }
        for (i = 0; i < m; i++)
        {
            count++;
            if (distinct[steps[i]] != 1)
            {
                distinct[steps[i]] = 1;
                distinct[counter] = 0;
                tem[counter] = count;
                counter--;
                if(counter==0)
                {
                    break;
                }
            }
        }

        for (i = 1; i <= n; i++)
        {
            cout << tem[i] << ' ';
        }

        cout << '\n';
    }
    return 0;
}