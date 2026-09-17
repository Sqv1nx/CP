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
    ull n;
    cin >> n;
    long long i = 1;
    long long ans = 0;

    while (i <= n)
    {
        long long v = n / i;
        long long next = n / v; 
        ans += v * (next - i + 1);
        i = next + 1;
    }
    cout << ans << '\n';
    return 0;
}