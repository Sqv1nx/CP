#include <iostream>
using namespace std;

void masti(int a[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int k;
        k = n;
        int i, j;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        masti(arr, k);
    }
    return 0;
}

void masti(int a[], int n)
{
    int i, k;
    int c = 0;
    bool zero = false;
    while (!zero)
    {
    if (a[0] != 0)
    {
        int temp;
        temp = a[0];
        for (i = 0; i < n; i++)
        {
            a[i] = a[i] - temp;
        }
        c++;
        
    }
    bool state = false;
    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            k = i;
            state = false;
            break;
        }
        else
            state = true;
    }
    if (state)
        zero = true;
    else
    {
        for (i = 0; i < k; i++)
        {
            if (a[i] == 0)
            {
                a[i] = a[i] + a[k];
            }
        }
        c++;
        
    }
}

if (zero)
    cout << c << '\n';
}

