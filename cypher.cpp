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
    char s[30];
    int i = 0, c;
    while ((c = getchar()) != EOF)
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    c = 26;
    while (c--)
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            int p;
            p = 'A' + ((s[i] - 'A' + c) % 26);
            printf("%c", p);
        }
        printf("\n");
    }
    return 0;
}