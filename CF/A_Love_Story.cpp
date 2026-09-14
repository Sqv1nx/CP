#include <string>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        char x[] = "codeforces";
        int i, n=0;
        cin>>s;
        for (i = 0; i < 10; i++)
        {
            if (s[i] != x[i])
            {
                n++;
            }
        }
        cout << n << '\n';
    }
    return 0;
}