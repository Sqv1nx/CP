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
        int n;
        cin>>n;
        string compa;
        cin>>compa;
        int minn=1,maxx=n;
        vi num(n);
        int i;
        for(i=n-2;i>=0;i--)
        {
            if(compa[i]=='<')
            {
                num[i+1]=minn;
                minn++;
            }
            else
            {
                num[i+1]=maxx;
                maxx--;
            }
        }
        num[0]=maxx;
        for(i=0;i<n;i++)
        {
            cout<<num[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}