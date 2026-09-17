#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int c;
    while ((c = getchar()) != '\n')
        ;
    while (t--)
    {
        int n = 0;
        char c;
        char word[101];
        while ((c = getchar()) != '\n')
        {
            word[n] = c;
            n = n + 1;
        }
        if (n <= 10)
        {
            int i;
            for (i = 0; i < n; i++)
            {
                cout << word[i];
            }
        }
        else
        {
            cout << word[0] << n - 2 << word[n - 1];
        }
        cout << '\n';
    }
    return 0;
}
