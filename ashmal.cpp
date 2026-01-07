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
    while (t--)
    {
        int n;
        cin >> n;
        string words[n];
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> words[i];
        }
        string final = "";
        if (n > 1)
        {
            final += words[0];
            for (i = 1; i < n; i++)
            {
                string temp1 = final;
                string temp2 = final;
                temp1 += words[i];
                temp2 = words[i] + temp2;
                if (temp1 <= temp2)
                {
                    final = temp1;
                }
                else
                {
                    final = temp2;
                }
            }
        }
        else
        {
            final += words[0];
        }
        cout << final << '\n';
    }
    return 0;
}