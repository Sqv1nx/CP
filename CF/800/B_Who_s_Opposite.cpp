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
        int a,b,c;
        cin>>a>>b>>c;
        int n;
        n=2*abs(a-b);
        if(a>n ||b>n || c>n)
        {
            cout<<"-1"<<'\n';
        }
        else
        {   if((c+abs(a-b))>n)
            cout<<(c+abs(a-b))%n<<'\n';
            else
            cout<<(c+abs(a-b))<<'\n';
        }
    }
    return 0;
}