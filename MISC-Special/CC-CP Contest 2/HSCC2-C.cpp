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
    int n;
    cin >> n;
    vi num(n);

    int i;
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    int maxx = 0;
    int j=0;
    int smol = num[0];
    for (i = 0; i < n; i++)
    {
        while(num[i]-num[j]>5)
        {
            j++;
        }
        maxx = max(maxx, i-j+1);
    }

    cout << maxx << '\n';
    return 0;
}