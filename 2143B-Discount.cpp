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
        ll n,k;
        cin>>n>>k;
        vector<ll> cost(n);
        vector<ll> disc(k);
        ll i,ans=0;
        for(i=0;i<n;i++)
        {
            cin>>cost[i];
            ans+=cost[i];
        }
        for(i=0;i<k;i++)
        {
            cin>>disc[i];
        }
        sort(cost.begin(),cost.end());
        sort(disc.begin(),disc.end());
        reverse(disc.begin(),disc.end());
        ll j=k-1;
        i=n-1;
        while(j>=0)
        {
            i=i-disc[j];
            if(i>=-1)
            ans=ans-cost[i+1];
            else
            {
                break;
            }
            j--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}