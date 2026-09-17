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
        int i, cm = 0;
        int arr[n];
        int arrc[n];
        int count[n]; // checks whter number in array of not
        
        int missing[n];
        for (i = 0; i < n; i++)
        {
            arr[i]=0;
            arrc[i]=0;
            count[i]=0;
            missing[i]=0;
        }
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] != 0)
                count[arr[i] - 1] = 1;
        }
        for (i = 0; i < n; i++)
        {
            if (count[i] != 1)
            {
                missing[cm] = i + 1;
                count[i] = 1;
                cm++;
            }
        }
        cm--;
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = missing[cm];
                cm--;
            }
            arrc[i] = arr[i];
        }
        sort(arrc, arrc + n);
        for (i = 0; i < n; i++)
        {
            if (arr[i] != arrc[i])
                break;
        }
        if (i == n)
        {
            cout << 0 << '\n';
        }
        else
        {
            for (cm = n - 1; cm >= 0; cm--)
            {
                if (arr[cm] != arrc[cm])
                    break;
            }
            cout << cm - i + 1 << '\n';
        }
    }
    return 0;
}