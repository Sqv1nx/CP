#include <bits/stdc++.h>
using namespace std;

int pali(int *a, int k)
{
    int i;
    
    for (i = 0; i < k/2; i++)
    {
        if (a[i] != a[k-1-i])
        {
            return 0;
            break;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = 1;
        int *arr = (int *)malloc(sizeof(int)*k);
        arr[0] = 0;
        int i;
        while (n != 0)
        {
            arr[k - 1] = n % 2;
            n = n / 2;
            if (n != 0)
            {
                k++;
                arr = (int *)realloc(arr, sizeof(int)*k);
            }
        }
        long c = k;

        for (i = 0; i <= c; i++)
        {
            int r = pali(arr, k);
            if (r == 1)
            {
                if (k % 2 == 0)
                {
                    cout << "YES" << '\n';
                    break;
                }
                else
                {
                    if (arr[(k / 2)] == 1)
                    {
                        cout << "NO" << '\n';
                        break;
                    }
                    else
                    {
                        cout << "YES" << '\n';
                        break;
                    }
                }
            }
            else
            {
                k++;
                arr = (int *)realloc(arr, sizeof(int)*k);
                arr[k - 1] = 0;
                if (i == c)
                {
                    cout << "NO" << '\n';
                }
            }
        }
        free(arr);
    }
    return 0;
}