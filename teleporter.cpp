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
    fp = fopen("teleport.in", "r");

    int a, b, x, y;
    fscanf(fp,"%d %d %d %d ", &a ,&b, &x, &y);
    fclose(fp);
    int ans= min(abs(a - b), min((abs(a - x) + abs(b - y)), (abs(a - y) + abs(b - x))));
    FILE *fw;
    fw= fopen("teleport.out","w");
    fprintf(fw,"%d",ans);
    fclose(fw);
    return 0;
}