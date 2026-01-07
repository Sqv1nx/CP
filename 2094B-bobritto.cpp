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
        int n,m,l,r;
        cin>>n>>m>>l>>r;
        int tally=n-m;
        while(l<0&&tally>0)
        {
            l++;
            tally--;
        }
        while(r>0 && tally>0)
        {
            r--;
            tally--;
        }
        cout<<l<<' '<<r<<'\n';
    }
    return 0;
}