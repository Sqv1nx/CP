#include <iostream>
using namespace std;

int dist(int);

int main()
{
    int i, j;
    int a, b;
    int mat[5][5];
    bool state = false;
    for (i = 0; i < 5 && !state ; i++)
    {
        for (j = 0; j < 5 && !state; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                a=i;
                b=j;
                state = true;
            }
        }
    }
    a = dist(a);
    b = dist(b);
    cout << (a + b);

    return 0;
}

int dist(int x)
{
    int p;
    if (x > 2)
    {
        p = (x - 2);
    }
    else
    {
        p = (2 - x);
    }
    return p;
}