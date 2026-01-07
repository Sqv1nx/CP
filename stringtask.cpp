#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    int i = 0;
    char a[101];
    char b[201];
    while ((c = getchar()) !='\n')
    {
        if (c >= 'A' && c <= 'Z')
        {
            a[i] = c - 'A' + 'a';
        }
        else
        {
            a[i] = c;
        }
        i++;
    }
    a[i] = '\0';
    
    int j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'o' || a[i] == 'i' || a[i] == 'u'|| a[i] == 'y')
        {
            ;
        }
        else
        {
            b[j] = '.';
            j++;
            b[j] = a[i];
            j++;
        }
    }
    b[j] = '\0';
    for (i = 0; b[i]!='\0'; i++)
    {
        cout << b[i];
    }
    return 0;
}