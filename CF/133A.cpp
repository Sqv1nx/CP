#include <iostream>
using namespace std;

int main()
{
    int c;
    int state=0;
    while((c=getchar())!=EOF)
    {
        if(c=='H'||c=='Q'||c=='9')
        {
            state=1;
            break;
        }
    }
    if(state==1)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
return 0;
}