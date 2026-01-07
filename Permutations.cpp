#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int i;
    vector<int> v(n);
    if (n ==2 || n== 3)
    {
        cout << "NO SOLUTION";
    }
    else if(n==4)
    {
        cout<<"2 4 1 3";
    }
    else
    {
        v[(n - 1) / 2] = n;
        v[n - 1] = 1;
        for (i = 0; i < (n - 1) / 2; i++)
        {
            v[i] = n - (1 + 2 * i);
        }
        for (i = (n + 1) / 2; i < n - 1; i++)
        {
            v[i] = n - (2 * (n - i - 1));
        }

        for (auto value : v)
        {
            cout << value << ' ';
        }
    }
    cout << '\n';
    return 0;
}
