#include <iostream>
using namespace std;

int main()
{
    char s[100];
    for (int i; i < 100; i++)
    {
        s[i] = '\0';
    }
    int i = 1, j;
    int c;
    bool state = true;
    c = getchar();
    s[0] = c;
    while ((c = getchar()) !='\n')
    {
        for (j = 0; j < i; j++)
        {
            if (s[j] == c)
            {
                state = false;
                break;
            }
        }
        if (state == true)
        {
            s[i] = c;
            i++;
        }
        state=true;
    }
    if (i % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }
    return 0;
}