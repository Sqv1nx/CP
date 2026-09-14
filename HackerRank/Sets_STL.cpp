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
    set <int> setstl;
    while (t--)
    {
        int v,x;
        cin>>v>>x;
        switch(v)
        {
            case 1:
            {
                setstl.insert(x);
                break;
            }
            case 2:
            {
                auto it=setstl.find(x);
                if(it!=setstl.end())
                    setstl.erase(it);
                break;
            }
            case 3:
            {
                auto it=setstl.find(x);
                if(it!=setstl.end())
                    cout<<"Yes"<<'\n';
                else
                    cout<<"No"<<'\n';
                break;
            }
            default:
                exit;
        }
    }
    return 0;
}