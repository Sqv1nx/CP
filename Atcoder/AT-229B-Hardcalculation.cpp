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
    int c, i;
    vector<char> a(20);
    vector<char> b(20);
    i = 20;
    while ((c = getchar()) != ' ')
    {
        a[i] = c;
        i--;
    }
    int sa = 20 - i;
    i = 20;
    while ((c = getchar()) != '\n')
    {
        b[i] = c;
        i--;
    }
    int sb = 20 - i;
    int fac=0;
    int k = min(sa, sb);
    if (sa != sb)
    {
        fac = sa - sb;
    }
    if (fac < 0)
    {
        for (i = 20; i > 20 - k; i--)
        {
            if ((a[i] - '0' + b[i + fac] - '0') >= 10)
            {
                cout << "Hard";
                return 0;
            }
        }
    }
    else if (fac > 0)
    {
        for (i = 20; i > 20 - k; i--)
        {
            if ((a[i - fac] - '0' + b[i] - '0') >= 10)
            {
                cout << "Hard";
                return 0;
            }
        }
    }
    else
    {
        for (i = 20; i > 20 - k; i--)
        {
            if ((a[i] - '0' + b[i] - '0') >= 10)
            {
                cout << "Hard";
                return 0;
            }
        }
    }

    cout << "Easy";
    return 0;
}