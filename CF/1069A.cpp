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
        vi count(1001);
        int n;
        cin>>n;
        int i;
        int distinct=0;
        
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(count[x]==0)
            distinct++;
            count[x]++;
            
        }
        bool state=false;
        while(!state)
        {
            if(count[distinct]==0)
            {
                count[distinct]++;
                distinct++;
            }
            else
            {
                state=true;
            }
        }
        cout<<distinct<<'\n';
    }
    return 0;
}