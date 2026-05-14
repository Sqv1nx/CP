#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        char mach[n];
        int i;
        int cb = 0;
        for (i = 0; i < n; i++)
        {
            cin >> mach[i];
            if (mach[i] == 'B')
                cb++;
        }
        while (q--)
        {
            int a;

            int c = 0;
            i = 0;
            cin >> a;
            if (cb == 0)
            {
                cout << a << '\n';
            }
            else
            {
                while (a != 0)
                {
                    if (mach[i] == 'A')
                    {
                        a = a - 1;
                        c++;
                    }
                    else
                    {
                        a = a / 2;
                        c++;
                    }
                    if (i < n - 1)
                    {
                        i++;
                    }
                    else
                    {
                        i = 0;
                    }
                }
                cout << c << '\n';
            }
        }
    }
    return 0;
}