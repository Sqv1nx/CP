#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x;
        cin >> y;
        if (x == y)
        {
            cout << '-' << '1' << '\n';
        }
        else if (x < y)
        {
            cout << '2' << '\n';
        }
        else if (y != 1)
        {
            if ((x - y) != 1)
            {
                cout << '3' << '\n';
            }
            else
            {
                cout << '-' << '1' << '\n';
            }
        }
        else
        {
            cout << '-' << '1' << '\n';
        }
    }
    return 0;
}