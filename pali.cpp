#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, k = n / 5, r = n % 5;
        char s[n+1];
        if (r > 0)
        {
            for (i = 0; i < 5*k; i=i+5)
            {
                s[i]='a';
                s[i+1]='e';
                s[i+2]='i';
                s[i+3]='o';
                s[i+4]='u';
            }
            switch (r)
            {
            case 1:
                s[i]='a';
                i++;
                break;
            case 2:
                s[i]='a';
                i++;
                s[i]='e';
                i++;
                break;
            case 3:
                s[i]='a';
                i++;
                s[i]='e';
                i++;
                s[i]='i';
                i++;
                break;
            case 4:
                s[i]='a';
                i++;
                s[i]='e';
                i++;
                s[i]='i';
                i++;
                s[i]='o';
                i++;
                break;
            default:
                break;
            }
        }
        else
        {
            for (i = 0; i <5* k; i=i+5)
            {
                s[i]='a';
                s[i+1]='e';
                s[i+2]='i';
                s[i+3]='o';
                s[i+4]='u';
            }
        }
        sort(s,s+n);
        s[n]='\0';
        for(i=0;i<n;i++)
        {
            cout<<s[i];
        }
        cout << '\n';
    }
    return 0;
}