#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef double ff;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef pair<int, int> pi;
#define REP(i, a, b) for (i = a; i < b; i++)
#define REPR(i, a, b) for (i = a; i > b; i--)
#define F first
#define S second
#define PB push_back
#define MP make_pair



// last n-ans cows are arragned in increasing order rest all k=can be placed in it




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *fp;
    fp = fopen("sleepy.in", "r");

    int n;
    fscanf(fp, "%d\n", &n);
    vi cow(n);

    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d ", &cow[i]);
        
    }
    fclose(fp);
    
    int ans=n-1;

    for(i=n-2;i>=0;i--)
    {
        if(cow[i]<cow[i+1])
        {
            ans=i;
        }
        else
        {
            break;
        }
    }
    
    FILE *fw;
    fw = fopen("sleepy.out", "w");
    fprintf(fw, "%d\n", ans);

    fclose(fw);
    return 0;
}