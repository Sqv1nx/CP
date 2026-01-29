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
        int n, x;
        cin >> n >> x;
        int i;
        vi num(n);
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        int cnt=1;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(num[i]*cnt>=x)
            {
                ans++;
                cnt=0;
            }
            cnt++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}