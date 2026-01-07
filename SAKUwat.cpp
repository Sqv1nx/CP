#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int valley[n][n];
        int smol[n];
        for (int p = 0; p < n; p++)
        {
            smol[p] = 0;
        }
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> valley[i][j];
            }
        }
        int sum = 0, d = n - 1, c = 0;
        i = n - 1;
        j = i;
        while (j >= 0)
        {
            smol[c] = valley[j - d][j];
            if (j == n - 1)
            {
                i--;
                d--;
                j = i;
                sort(smol, smol + n);
                if (smol[0] < 0)
                {
                    sum = sum + smol[0];
                }
                c = 0;
            }
            else
            {
                j++;
            }
            c++;
            if (j == i)
            {
                c = 0;
                for (int p = 0; p < n; p++)
                {
                    smol[p] = 0;
                }
            }
        }
        d = n - 1;
        i = n - 1;
        j = i;
        while (j >= 1)
        {
            smol[c] = valley[j][j - d];
            if (j == n - 1)
            {
                i--;
                d--;
                j = i;
                sort(smol, smol + n);
                if (smol[0] < 0)
                {
                    sum = sum + smol[0];
                }
                c = 0;
            }
            else
            {
                j++;
            }
            c++;
            if (j == i)
            {
                c = 0;
                for (int p = 0; p < n; p++)
                {
                    smol[p] = 0;
                }
            }
        }
        cout << (-1 * sum) << '\n';
    }
    return 0;
}