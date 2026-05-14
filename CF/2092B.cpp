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
        char a[n + 1];
        char b[n + 1];
        bool state = false;
        int i = 0;
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
            cin >> b[i];
        int cz = 0, co = 0, cz1 = 0, co1 = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] == '0')
                cz++;
        }
        if (cz == n)
        {
            cout << "YES\n";
            state = true;
        }
        cz = 0;
        i = 0;
        while (i < n - 1 && !state)
        {
            if (a[i] == '0')
            {
                cz++;
            }
            else
            {
                co++;
            }
            if (b[i + 1] == '0')
            {
                cz++;
            }
            else
            {
                co++;
            }
            i = i + 2;
        }
        if (n % 2 == 1)
        {
            if (a[n - 1] == '0')
            {
                cz++;
            }
            else
            {
                co++;
            }
        }

        i = 0;
        while (i < n - 1 && !state)
        {
            if (b[i] == '0')
            {
                cz1++;
            }
            else
            {
                co1++;
            }
            if (a[i + 1] == '0')
            {
                cz1++;
            }
            else
            {
                co1++;
            }
            i = i + 2;
        }
        if (n % 2 == 1)
        {
            if (b[n - 1] == '0')
            {
                cz1++;
            }
            else
            {
                co1++;
            }
        }

        if (cz >= co && !state && cz1 >= co1-1)
        {
            cout << "YES\n";
        }
        else if (!state)
        {
            cout << "NO\n";
        }
    }
    return 0;
}