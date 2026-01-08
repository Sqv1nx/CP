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
        int n, k;
        cin >> n >> k;
        int i = 0;
        int Slep = 0;
        vector<char> clas;
        for (i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            clas.PB(x);
        }
        int counter=k+1;
        for(i=0;i<n;i++)
        {
            if(clas[i]=='1')
            {
                counter=0;
            }
            else
            {
                if(counter<k)
                {
                    counter++;
                }
                else
                {
                    Slep++;
                }
            }
        }
        cout << Slep << '\n';
    }
    return 0;
}