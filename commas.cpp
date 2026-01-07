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
    ull n,count=0;
    vull check ={999,999999,999999999,999999999999,999999999999999};
    int i=0;
    bool done=false;
    cin>>n;
    while(!done && i<5)
    {
        if(n>check[i])
        {
            if(i>0)
            {
                count+=(i)*(check[i]-check[i-1]);
            }
        }
        else
        {
            done=true;
            if(i>0)
            {
                count+=(i)*(n-check[i-1]);
            }
        }
        i++;
    }
    if(n==1000000000000000)
    count+=5;
    cout<<count<<'\n';
    
    return 0;
}