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
        vi arr(n);
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int of, ef, el, ol;
        for (i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                ef = i;
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
            {
                of = i;
                break;
            }
        }

        for (i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == 0)
            {
                el = i;
                break;
            }
        }

        for (i = n - 1; i >= 0; i--)
        {
            if (arr[i] % 2 == 1)
            {
                ol = i;
                break;
            }
        }

        int ans = 0;
        if (ol > el && of < ef)
        {
            ans = 0;
        }
        else if (el > ol && ef < of)
        {
            ans = 0;
        }
        else
        {
            int x, y;
            x = abs(ol - el);
            y = abs(of - ef);
            ans = min(x, y);
        }
        cout << ans << '\n';
    }
    return 0;
}