#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m,a;
    cin>>n>>m>>a;
    if(n%a==0&&m%a==0)
    {
        cout<<(n/a)*(m/a);
    }
    else if(n%a==0&&m%a!=0)
    {
        cout<<(n/a)*(m/a+1);
    }
    else if(n%a!=0&&m%a==0)
    {
        cout<<(m/a)*(n/a+1);
    }
    else
    {
        cout<<(m/a+1)*(n/a+1);
    }
    return 0;
}