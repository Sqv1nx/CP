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
        int i;
        vi num(n);
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        vi cnt(10, 0);
        int ans = 0;
        for (i = 0; i < n; i++)
        {
            cnt[num[i]]++;
            if (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1)
            {
                ans = i+1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}