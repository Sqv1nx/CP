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
        unsigned long long int r, c;
        cin >> r;
        cin >> c;
        if (r > c)
        {
            if (r % 2 == 0)
                cout << (r * r) + (unsigned long long int)1 - c << '\n';
            else
            {
                unsigned long long int k = r-1;
                cout << (k * k) + c << '\n';
            }
        }
        else if (r < c)
        {
            if (c % 2 == 1)
                cout << (c * c) + (unsigned long long int)1 - r << '\n';
            else
            {
                unsigned long long int k = c-1;
                cout << (k * k) + r << '\n';
            }
        }
        else
        {
            cout << (r * r) + (unsigned long long int)1 - c << '\n';
        }
    }
    return 0;
}