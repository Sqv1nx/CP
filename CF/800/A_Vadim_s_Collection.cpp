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
        string magik;
        cin >> magik;
        int i;
        vi num(10, 0);
        for (i = 0; i < (int)magik.size(); i++)
        {
            num[magik[i]-'0']++;
        }
        string final="";
        int j;
        for (i = 1; i <= 10; i++)
        {
            j = 10 - i;
            while (j < 10)
            {
                if (num[j] > 0)
                {
                    final+=j+'0';
                    num[j]--;
                    break;
                }
                j++;
            }
        }
        cout << final << '\n';
    }
    return 0;
}