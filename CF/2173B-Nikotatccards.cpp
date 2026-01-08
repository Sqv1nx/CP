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
        cin>>n;
        vector<ll> red(n);
        vector<ll> blue(n);
        int i;
        ll maxx=0,minn=0;
        REP(i, 0, n)
        {
            cin >> red[i];
        }
        REP(i, 0, n)
        {
            cin >> blue[i];
        }
        for(i=0;i<n;i++)
        {
            ll tempmx =maxx;
            ll tempmn = minn;
            maxx=max(tempmx-red[i],blue[i]-tempmn);
            minn=min(tempmn-red[i],blue[i]-tempmx);
        }
        cout<<maxx<<'\n';
    }
    return 0;
}