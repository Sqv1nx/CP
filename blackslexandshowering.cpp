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
        vi a(n);
        vi diff(n - 1);
        int i, sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int prob=0;
        for(i=0;i<n-1;i++)
        {
            sum+=abs(a[i+1]-a[i]);
        }
        for (i = 1; i < n - 2; i++)
        {
            int temp = abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i - 1]);
            prob=max(temp,prob);
        }
        if(prob==0)
        prob=a[n-1]-a[n-2];
        
        cout << sum-prob << '\n';
    }
    return 0;
}