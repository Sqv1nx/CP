#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<int,int> pi;
#define REP(i,a,b)  for(i=a;i<b;i++)
#define REPR(i,a,b)  for(i=a;i>b;i--)
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
        ll n,m;
        cin>>n>>m;
        set<ll> candy;
        int i;
        for(i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            candy.insert(x);
        }
        ll sze=candy.size();
        for(i=0;i<m;i++)
        {
            ll x;
            cin>>x;
            candy.insert(x);
            if(candy.size()==sze)
            {
                cout<<"YES\n";
            }
            else
            {
                sze++;
                cout<<"NO\n";
            }
        }
    }
    return 0;
}