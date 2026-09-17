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

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, k;
//         cin >> n >> k;
//         ll ca = n, cb = 1;
//         ll i;
//         // if(n%2==0)
//         // {
//         //     k=k%n;
//         // }
//         // else
//         // {
//         //     k=k%(n*n);
//         // }
//         // if(k==0)
//         // {
//         //     k=n;
//         // }
//         for (i = 1; i < k; i++)
//         {
//             ca--;
//             cb = (cb + 1) % n;
//             if (cb == 0)
//             {
//                 cb = n;
//             }
//             if (ca == 0)
//             {
//                 ca = n;
//             }
//             if (ca == cb)
//             {
//                 cb = (cb + 1) % n;
//                 if (cb == 0)
//                 {
//                     cb = n;
//                 }
//             }
//         }
//         if (cb == 0)
//         {
//             cb = n;
//         }
//         cout << cb << '\n';
//     }
//     return 0;
// }
// got some mtahs issue

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        k--;
        ll f=n/2;
        k=(k+(n%2)*k/f)%n+1;
        cout<<k<<'\n';
    }
    return 0;
}