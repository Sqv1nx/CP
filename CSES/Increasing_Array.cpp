#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    long long int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    auto it = v.begin();
    auto itn = it;
    itn++;
    for (; itn != v.end(); it++, itn++)
    {
        if (*it > *itn)
        {
            sum += (long long int)*it - *itn;
            *itn = *it;
        }
    }
    cout << sum << '\n';
    return 0;
}