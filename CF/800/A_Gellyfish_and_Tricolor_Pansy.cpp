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
        pi gel,flow;
        cin>>gel.first;
        cin>>flow.first;
        cin>>gel.second;
        cin>>flow.second;
        if(gel.first>=flow.first)
        {
            if(gel.second>=flow.first)
            {
                cout<<"Gellyfish"<<'\n';
            }
            else
            {
                if(gel.second>=flow.second)
                {
                    cout<<"Gellyfish"<<'\n';
                }
                else
                {
                    cout<<"Flower"<<'\n';
                }
            }
        }
        else
        {
            if(flow.second>gel.first)
            {
                cout<<"Flower"<<'\n';
            }
            else
            {
                if(flow.second>gel.second)
                {
                    cout<<"Flower"<<'\n';
                }
                else
                {
                    cout<<"Gellyfish"<<'\n';
                }
            }
        }
    }
    return 0;
}