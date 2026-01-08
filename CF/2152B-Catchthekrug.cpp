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
        int n,rk,ck,rd,cd;
        cin>>n>>rk>>ck>>rd>>cd;
        int x,y;
        if(rk>rd)
        {
            x=n-rd;
        }
        else if(rk<rd)
        {
            x=rd;
        }
        else
        {
            x=0;
        }

        if(ck>cd)
        {
            y=n-cd;
        }
        else if(ck<cd)
        {
            y=cd;
        }
        else
        {
            y=0;
        }

        int ans=max(x,y);
        cout<<ans<<'\n';
    }
    return 0;
}