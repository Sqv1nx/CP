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
        int k;
        pi a, b;
        cin >> k;
        cin >> a.first;
        cin >> b.first;
        cin >> a.second;
        cin >> b.second;
        int meat = 0;
        if (k < a.first && k < b.first)
        {
            meat = 0;
        }
        else if (k >= a.first && k < b.first)
        {
            meat += ((k - a.first) / a.second + 1);
        }
        else if (k < a.first && k >= b.first)
        {
            meat += ((k - b.first) / b.second + 1);
        }
        else
        {
            if (a.second > b.second)
            {
                meat += ((k - b.first) / b.second + 1);
                k = k - (meat * b.second);
                if(k>=a.first)
                meat += ((k - a.first) / a.second + 1);
            }
            else
            {
                meat += ((k - a.first) / a.second + 1);
                k = k - (meat * a.second);
                if(k>=b.first)
                meat += ((k - b.first) / b.second + 1);
            }
        }
        cout << meat << '\n';
    }
    return 0;
}