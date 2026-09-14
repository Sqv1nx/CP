#include <iostream>
using namespace std;

int main()
{
    int t;
    int a = 0;
    cin >> t;
    while (t--)
    {
        char s[3];

        for (int i = 0; i < 3; i++)
        {
            cin >> s[i];
        }
        if (s[1] == '+')
        {
            a = a + 1;
        }
        if(s[1]== '-')
        {
            a = a - 1;
        }
    }
    cout << a;
    return 0;
}