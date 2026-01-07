#include <iostream>
using namespace std;

int main()
{
    char futbol[100];
    int c, i = 0;
    while ((c = getchar()) != '\n' && i < 100)
    {
        futbol[i] = c;
        i++;
    }
    int k = i;
    int n = 0, x;
    x = futbol[0];
    for (i = 0; i < k; i++)
    {
        if (futbol[i] == x)
        {
            n++;
            if (n == 7)
            {
                break;
            }
        }
        else
        {
            x = futbol[i];
            n = 1;
        }
    }
    if (n >= 7)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}