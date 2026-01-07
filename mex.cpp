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
        int arr[n];
        int i;
        int cz = 0, cnz = 0;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        if (arr[0] != 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (arr[i] == 0)
                {
                    cz++;
                }
                else
                {
                    cnz++;
                }
            }
            if (cnz >= (cz - 1))
            {
                cout << 0 << '\n';
            }
            else
            {
                if (cz == n)
                {
                    cout << 1 << '\n';
                }
                else if (arr[cz] != 1)
                {
                    cout << 1 << '\n';
                }
                else if (arr[cz] == 1 && arr[n - 1] != 1)
                {
                    cout << 1 << '\n';
                }
                else
                {
                    cout << 2 << '\n';
                }
            }
        }
    }
    return 0;
}