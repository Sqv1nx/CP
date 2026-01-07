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
        vi points(n);

        int i;
        for (i = 0; i < n; i++)
        {
            cin >> points[i];
        }
        vector<float> radii(n);
        radii[0] = (float)(points[1] - points[0]) / 2.0;
        for (i = 1; i < n-1; i++)
        {
            radii[i] = min(((float)(points[i] - points[i - 1]) - radii[i - 1]),(float)((points[i + 1] - points[i]))-(float)0.1);
        }
        radii[n - 1] = ((float)(points[n - 1] - points[n - 2]) - radii[n - 2]);
        int touch = 0;
        for (i = 1; i < n; i++)
        {
            double a=(double)points[i] - points[i - 1];
            double b=(double)(radii[i] + radii[i - 1]);
            if (abs(a-b)< 1e-3)
            {
                touch++;
            }
        }
        cout << touch << '\n';
    }
    return 0;
}