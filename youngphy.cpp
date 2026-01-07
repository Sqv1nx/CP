#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    struct vector
    {
        int x;
        int y;
        int z;
    };
    typedef vector vec;
    typedef vec* vecptr;
    vecptr force;
    force=(vecptr)malloc(n*sizeof(vec));
    int i;
    for(i=0;i<n;i++)
    {
        cin>>force[i].x>>force[i].y>>force[i].z;
    }
    int sx=0,sy=0,sz=0;
    for(i=0;i<n;i++)
    {
        sx=force[i].x+sx;
        sy=force[i].y+sy;
        sz=force[i].x+sz;
    }
    if(sx==0&&sy==0&&sz==0)
    {
        cout<<"YES"<<'\n';
    }
    else
    cout<<"NO"<<'\n';
    return 0;
}