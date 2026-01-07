#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int f;
        cin>>f;
        long long int *field;
        long long int  sum=0;
        long long int c=0,k;
        field=(long long int*)malloc(f*sizeof(long long int));
        int i;
        for(i=0;i<f;i++)
        {
            cin>>k;
            if(k%2==0)
            {
                sum=sum+k;
            }
            else
            {
                field[c]=k;
                c++;
            }
        }
        // long long int *temp=(long long int *)realloc(field,c*sizeof(long long int));
        // if(temp==NULL)
        // {
        //     free(field);
        //     return 1;
        // }
        // else
        // field=temp;

        sort(field,field+c);
        f=c;
        k=f-1;
        c=0;
        while(k>=c)
        {
            sum=sum+field[k];
            k--;
            c++;
        }
        free(field);
        if(f>0)
        cout<<sum<<'\n';
        else
        cout<<0<<'\n';
    }
    return 0;
}