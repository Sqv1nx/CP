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
        string bin;
        cin >> bin;
        int i;
        vi zelo;
        for (i = 0; i < n; i++)
        {
            if (bin[i] == '0')
            {
                zelo.push_back(i + 1);
            }
        }
        int sze = zelo.size();
        cout<<sze<<'\n';
        for (i = 0; i < sze; i++)
        {
            cout << zelo[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}