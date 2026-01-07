#include <iostream>
using namespace std;
int sum(int *, int, int);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int l, r;
        bool found = false;
        int s1, s2, s3;
        for (r = 1; r < n && !found; r++)
        {
            for (l = 1; l < r; l++)
            {
                s1 = sum(arr, 0, l - 1) % 3;
                s2 = sum(arr, l, r - 1) % 3;
                s3 = sum(arr, r, n - 1) % 3;
                if ((s1 == s2 && s2 == s3 && s3 == s1) || (s1 != s2 && s2 != s3 && s1 != s3))
                {
                    cout << l << ' ' << r << '\n';
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            cout << '0' << ' ' << '0' << '\n';
        }
    }
    return 0;
}

int sum(int A[], int str, int stp)
{
    int i;
    int sum = 0;
    for (i = str; i <= stp; i++)
    {
        sum = sum + A[i];
    }
    return sum;
}