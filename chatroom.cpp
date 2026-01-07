#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[101];
    int counth[101] = {0};
    int counte[101] = {0};
    int countl[101] = {0};
    int counto[101] = {0};
    int ch = 0, ce = 0, cl = 0, co = 0;
    int cH=0,cE=0,cO=0, cL1 = 0, cL2 = 0;
    int i = 0;
    for (i = 0; i < 101; i++)
    {
        cin >> s[i];
        if (s[i] == 'h')
        {
            counth[ch] = i;
            ch++;
        }
        else if (s[i] == 'e')
        {
            counte[ce] = i;
            ce++;
        }
        else if (s[i] == 'l')
        {
            countl[cl] = i;
            cl++;
        }
        else if (s[i] == 'o')
        {
            counto[co] = i;
            co++;
        }
    }
    if (ch > 0)
    {
        cH = counth[0];
        for (i = 0; i < ce; i++)
        {
            if (counte[i] > cH)
            {
                cE = counte[i];
                break;
            }
        }
        for (i = 0; i < cl; i++)
        {
            if (countl[i] > cE)
            {
                cL1 = countl[i];
                break;
            }
        }

        for (; i < cl; i++)
        {
            if (countl[i] > cL1)
            {
                cL2 = countl[i];
                break;
            }
        }
        for (i = 0; i < co; i++)
        {
            if (counto[i] > cL2)
            {
                cO = counto[i];
                break;
            }
        }
        if (cE != 0 && cL1 != 0 && cL2 != 0 && cO != 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
        cout << "NO\n";

    return 0;
}