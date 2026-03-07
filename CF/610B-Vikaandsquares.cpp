#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
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

    int n;
    cin >> n;
    vull v(n);
    int i;
    REP(i, 0, n)
    {
        cin >> v[i];
    }

    int minn = 0, minnn = 0;
    REP(i, 0, n)
    {
        if (v[i] < v[minnn])
        {
            minnn = i;
        }
    }
    int c = 0;
    vull minc;
    REP(i, 0, n)
    {
        if (v[i] == v[minnn])
        {
            c++;
            minc.PB(i);
        }
    }
    if (c == n)
    {
        cout << ((ull)n) * v[minnn] << '\n';
    }
    else if (c == 1)
    {
        cout << (((ull)n) * v[minnn]) + (ull)(n - 1) << '\n';
    }
    else
    {

        REP(i, 0, n)
        {
            if (v[i] <= v[minn])
            {
                minn = i;
                if (minn != minnn && v[minn] == v[minnn])
                {
                    break;
                }
            }
            if (v[i] < v[minnn])
            {
                minnn = i;
            }
        }
        ull diffsum = minc[1] - minc[0];
        
            REP(i, 0, c - 1)
            {
                if (diffsum < minc[i + 1] - minc[i])
                {
                    diffsum = minc[i + 1] - minc[i];
                }
            }

            if (diffsum < minc[0] + (ull)n - minc[c - 1])
                diffsum = minc[0] + (ull)n - minc[c - 1];

            cout << (((ull)n) * v[minnn]) + diffsum - (ull)1 << '\n';
        
    }
    return 0;
}


//BETTER CODE





// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<ll> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     // 1) find minimum value
//     ll mn = *min_element(a.begin(), a.end());

//     // 2) collect all positions of mn
//     vector<int> pos;
//     for (int i = 0; i < n; i++) {
//         if (a[i] == mn) pos.push_back(i);
//     }

//     // 3) compute maximum gap (circular)
//     ll best = 0;
//     int c = pos.size();
//     for (int i = 0; i < c; i++) {
//         int j = (i + 1) % c;
//         ll gap = (pos[j] - pos[i] - 1 + n) % n;
//         best = max(best, gap);
//     }

//     // Final result
//     cout << mn * n + best << "\n";
//     return 0;
// }
