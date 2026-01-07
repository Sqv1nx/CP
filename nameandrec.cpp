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
        string name;
        cin >> name;
        if (name.size() == 5)
        {
            int i, countT=0,counti=0,countm=0,countu=0,countr= 0;
            for (i = 0; i < name.size(); i++)
            {
                char x;
                x = name[i];
                if (x == 'T')
                {
                    countT=1;
                }
                else if (x == 'i')
                {
                    counti=1;
                }
                else if (x == 'm')
                {
                    countm=1;
                }
                else if (x == 'u')
                {
                    countu=1;
                }
                else if (x == 'r')
                {
                    countr=1;
                }
            }
            if (countT==1&&counti==1&&countm==1&&countu==1&&countr==1)
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}