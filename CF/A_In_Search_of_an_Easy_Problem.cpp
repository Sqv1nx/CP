#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i;
        int count[101];
        for (i = 0; i < 101; i++)
        {
            count[i] = 0;
        }
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        for (i = 0; i < 101; i++)
        {
            if (count[i] == 0)
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}