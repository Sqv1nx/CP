#include <bits/stdc++.h>
using namespace std;

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
        int k,x;
        int pizza = 0;

        while (n > 7)
        {
            k=n/3;
            pizza+=k;
            x=n-3*k;
            n=n/3+x;
        }
        if (n == 4 || n == 3 )
        {
            pizza += 1;
        }
        if (n == 6|| n == 5)
        {
            pizza += 2;
        }
        if (n == 7)
        {
            pizza += 3;
        }

        cout << pizza << '\n';
    }
    return 0;
}