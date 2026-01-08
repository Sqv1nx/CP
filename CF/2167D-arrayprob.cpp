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
        ll n;
        cin>>n;
        vector<ll> nums(n);
        ll i;
        for(i=0;i<n;i++)
        {
            cin>>nums[i];
        }
        ll j;
        bool done=false;
        ll ans=1;
        for(i=0;!done;i++)
        {
            ans++;
            for(j=0;j<n;j++)
            {
                if(gcd(ans,nums[j])==1)
                {
                    done=true;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}