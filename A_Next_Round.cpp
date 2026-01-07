#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v;
    int i;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int no=v[k-1];
    i=0;
    if(no>0)
    {
        for(auto value : v)
        {
            if(no<=value)
            i++;
            else
            break; 
        }
    }
    else
    {
        for(auto value : v)
        {
            if(no<value)
            i++;
            else
            break; 
        }
    }
    cout<<i<<'\n';
    return 0;
}