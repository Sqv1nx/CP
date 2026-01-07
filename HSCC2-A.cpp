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
        int i,j;
        vi num(n);
        int minn;
        for(i=0;i<n;i++)
        {
            cin>>num[i];
        }
        minn=num[0];
        int tmp=minn;
        for(i=0;i<n;i++)
        {
            tmp=num[i];
            minn=min(minn,tmp);
            for(j=i+1;j<n;j++)
            {
                tmp=tmp|num[j];
                if(tmp>minn)
                tmp=minn;
                else
                minn=tmp;
            }
        }
        cout<<minn<<'\n';
    }
    return 0;
}