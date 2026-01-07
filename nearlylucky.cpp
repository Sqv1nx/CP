#include <iostream>
using namespace std;

int main()
{

    int c;
    int n = 0;
    while ((c = getchar()) != '\n')
    {
        if (c - '0' == 4 || c - '0' == 7)
        {
            n++;
        }
    }
    if (n == 4 || n == 7)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}