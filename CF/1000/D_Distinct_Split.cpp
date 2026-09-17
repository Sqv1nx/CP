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
        char s[n];
        int count[26] = {0};
        int countL[n] = {0};
        int countR[n] = {0};
        int i;

        for (i = 0; i < n; i++)
        {
            cin >> s[i];
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] == 1)
            {
                countL[i] = 1;
            }
        }
        for (i = 0; i < 26; i++)
        {
            count[i] = 0;
        }
        for (i = n - 1; i >= 0; i--)
        {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] == 1)
            {
                countR[i] = 1;
            }
        }
        for (i = 1; i < n; i++)
        {
            countL[i] = countL[i] + countL[i - 1];
        }
        for (i = n - 2; i >= 0; i--)
        {
            countR[i] = countR[i] + countR[i + 1];
        }

        int k = 0, maxx = 0;
        for (k = 0; k < n - 1; k++)
        {
            if (countL[k] + countR[k + 1] > maxx)
            {
                maxx = countL[k] + countR[k + 1];
            }
        }
        cout << maxx << '\n';
    }
    return 0;
}