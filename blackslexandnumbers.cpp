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
        int n,i;
        cin>>n;
        vi num(n);

        for(i=0;i<n;i++)
        {
            cin>>num[i];
        }

        sort(num.begin(),num.end());
        int ans;
        if(num[1]-num[0]>num[0])
        {
            ans=num[1]-num[0];
        }
        else
        {
            ans=num[0];
        }
        cout<<ans<<'\n';
    }
    return 0;
}