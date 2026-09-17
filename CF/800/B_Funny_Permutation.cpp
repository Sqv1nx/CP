#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n];
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        int q[n];
        for (i = 0; i < n; i++)
        {
            q[i] =n + 1 - p[i];
        }
        for (i = 0; i < n; i++)
        {
            cout << q[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
