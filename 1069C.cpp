#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<int, int> pi;
#define REP(i, a, b) for (i = a; i < b; i++)
#define REPR(i, a, b) for (i = a; i > b; i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string buffer;
    getline(cin, buffer);
    while (t--)
    {
        int count[26] = {0};
        string s;
        string t;
        int i;
        getline(cin, s);
        getline(cin, t);
        int ss = s.size();
        int st = t.size();

        for (i = 0; s[i] != '\0'; i++)
        {
            count[s[i] - 'a']--;
        }
        for (i = 0; t[i] != '\0'; i++)
        {
            count[t[i] - 'a']++;
        }
        char final[10001];
        bool imp = false;
        int k = 0, j = 0;
        for (i = 0; i < 26; i++)
        {
            if (count[i] >= 0 && (s[j] > 'a' + i || j==ss))
            {
                while (count[i]--)
                {
                    final[k] = 'a' + i;
                    k++;
                }
            }
            else if (s[j] <= 'a' + i && j<ss)
            {
                final[k] = s[j];
                k++;
                j++;
                i--;
            }
            else
            {
                imp = true;
                break;
            }
        }

        if (imp)
        {
            cout << "Impossible" << '\n';
        }
        else
        {
            
            for (i = 0; i < st; i++)
            {
                cout << final[i];
            }
            cout << '\n';
        }
    }
    return 0;
}