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
        ff n,b,h;
        ff hmax=1000000000000.00;
        cin>>n>>b>>h;
        vi height(n+1);
        int i;
        REP(i,0,n)
        {
            cin>>height[i];
        }
        height[n]=hmax;
        ff bi,hi,area=0;
        REP(i,0,n)
        {
            if(height[i+1]-height[i]>=h)
            {
                area+=0.5*b*h;
            }
            else
            {
                hi=height[i+1]-height[i];
                bi=b-b*(hi/h);
                area+=0.5*hi*(b+bi);
            }
        }

        cout << fixed << setprecision(10) << area <<'\n';

    }
    return 0;
}