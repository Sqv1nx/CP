#include <iostream>
#include <algorithm>
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
        cin>>n;
        int *arr;
        arr = (int *)malloc(n * sizeof(int));
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        cout << arr[n-1] << '\n';
    }

    return 0;
}