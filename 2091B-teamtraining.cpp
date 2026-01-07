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
        int n, x;
        cin >> n >> x;
        int i;
        vi num(n);
        for (i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        int jyada = 0;
        while (n > 0)
        {
            int temp = x / num[n - 1];
            if (temp * num[n - 1] == x && temp <= n)
            {
                for (i = 0; i < temp; i++)
                {
                    num.pop_back();
                }
                jyada++;
                n = n - temp;
            }
            else if (temp+1 <= n)
            {
                temp++;
                for (i = 0; i < temp; i++)
                {
                    num.pop_back();
                }
                jyada++;
                n = n - temp;
            }
            else
            {
                num.pop_back();
                n--;
            }
        }

        cout << jyada << '\n';
    }
    return 0;
}