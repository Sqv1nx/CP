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
        string bin;
        cin >> bin;
        int i;
        int sze = bin.size();
        int grps = 0;
        bool ptr = false;
        for (i = 0; i < sze; i++)
        {
            if (!ptr)
            {
                if (bin[i] == '0')
                {
                    grps++;
                    ptr = true;
                }
            }
            else
            {
                if (bin[i] == '1')
                {
                    ptr = false;
                }
            }
        }
        if (grps <= 2)
        {
            cout << grps << '\n';
        }
        else
        {
            cout << 2 << '\n';
        }
    }
    return 0;
}