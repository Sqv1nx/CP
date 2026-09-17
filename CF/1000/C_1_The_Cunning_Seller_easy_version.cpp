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
    vector<ll> costs(1001);
    int i;
    costs[0] = 3;
    costs[1] = 10;
    for (i = 2; i < 20; i++)
    {
        costs[i] = 6 * costs[i - 1] - 9 * costs[i - 2];
    }
    vector<ll> pow3(20);
    pow3[0]=1;
    for (i = 1; i < 20; i++)
    {
        pow3[i]=3*pow3[i-1];
    }
    while (t--)
    {
        ll n;
        cin >> n;
        ll powee = -1;
        ll tmp = n;
        ll cost = 0;
        while (tmp != 0)
        {
            tmp = tmp / 3;
            powee++;
        }
        tmp=pow3[powee];
        if (tmp == n)
        {
            cout << costs[powee] << '\n';
        }
        else
        {
            while (n > 0)
            {
                if (n >= tmp)
                {
                    ll c=n/tmp;
                    cost=cost+c*costs[powee];
                    n=n%tmp;
                }
                    powee--;
                    tmp=pow3[powee];
            }
            cout << cost << '\n';
        }
    }
    return 0;
}