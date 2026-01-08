#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<int, int> pi;
#define REP(i, a, b) for (i = a; i < b; i++)
#define REPR(i, a, b) for (i = a; i > b; i--)
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
        cin >> n;
        vi num(n);
        int i,j,n1=0,n2=0;
        bool mila=false;
        for(i=0;i<n;i++)
        {
            cin>>num[i];
        }
        for(i=0;i<n && !mila;i++)
        {
            for(j=i+1; j<n && !mila;j++)
            {
                int x=(num[j]%num[i]);
                if(x%2==0)
                {
                    n1=num[i];
                    n2=num[j];
                    mila=true;
                }
            }
        }
        if (mila)
        {
            cout << n1 << ' ' << n2 << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}