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

    ll n;
    cin >> n;
    multiset<pair<ll, string>> listb;
    ll i;
    for (i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        ll marks;
        cin >> marks;
        pair<ll, string> p = {100 - marks, name};
        listb.insert(p);
    }
    for (auto it = listb.begin(); it != listb.end(); it++)
    {
        cout << it->second << ' ' << 100 - (it->first) << '\n';
    }

    return 0;
}