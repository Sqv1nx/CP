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
        int n,k;
        cin>>n>>k;
        multiset<ll> candy;
        int i;
        for(i=0;i<n;i++)
        {
            ll cnt;
            cin>>cnt;
            candy.insert(cnt);
        }
        ll sum=0;
        for(i=0;i<k;i++)
        {
            auto it=(--candy.end());
            ll cnt=(*it);
            sum+=cnt;
            candy.erase(it);
            candy.insert(cnt/2);
        }
        cout<<sum<<'\n';
    }
    return 0;
}