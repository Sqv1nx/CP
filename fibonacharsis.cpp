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
        int diff = 0;
        int i, itr;
        for (i = 0; i <= (n / 2); i++)
        {
            itr = 0;
            int curr = n;
            int x = curr - i;
            int y = curr - x;
            itr++;

            while (y >= 0 && itr < k)
            {
                curr = x;
                x = y;
                y = curr - x;
                itr++;
            }

            if (itr == k)
            {
                diff++;
            }
        }
        cout << diff << '\n';
    }
    return 0;
}