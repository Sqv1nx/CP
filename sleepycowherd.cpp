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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FILE *fp;
    fp = fopen("herding.in", "r");

    vi spot(3);
    fscanf(fp,"%d %d %d ", &spot[0] ,&spot[1], &spot[2]);
    fclose(fp);
    int min,maxx;
    sort(spot.begin(),spot.end());
    if(spot[1]-spot[0]==1 && spot[2]-spot[1]==1)
    {
        min=0;
        maxx=0;
    }
    else if(spot[1]-spot[0]==2 || spot[2]-spot[1]==2)
    {
        min=1;
        maxx=max((spot[1]-spot[0]),(spot[2]-spot[1]))-1;
    }
    else
    {
        min=2;
        maxx=max((spot[1]-spot[0]),(spot[2]-spot[1]))-1;
    }
    FILE *fw;
    fw= fopen("herding.out","w");
    fprintf(fw,"%d\n",min);
    fprintf(fw,"%d\n",maxx);
    fclose(fw);
    return 0;
}