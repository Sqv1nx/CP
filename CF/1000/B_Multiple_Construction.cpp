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
        int *arr;
        arr = (int *)calloc(2 * n, sizeof(int));
        arr[2 * n - 1] = n;
        arr[n - 1] = n;
        int k = n - 1;
        int i = 0, j = 2 * (n - 1);
        while (k)
        {
            arr[i] = k;
            arr[j] = k;
            i++;
            j--;
            k--;
        }
        for (i = 0; i < 2*n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}