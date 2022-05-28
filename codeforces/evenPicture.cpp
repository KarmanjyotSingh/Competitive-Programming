#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define YES cout << 'YES' << endl
#define NO cout << 'NO' << endl
void swap(lli *a, lli *b)
{
    lli t = *b;
    *b = *a;
    *a = t;
}
int compare(lli a, lli b) { return a > b; }
#define TC    \
    lli t;    \
    cin >> t; \
    while (t--)
#define needforspeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABD(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
#define all(a) a.begin(), a.end()
#define pb push_back
#define FOR (i, n) for (i = 0; i < n; i++)
#define FORR(i, n) for (i = n - 1; i >= 0; i--)
#define input(a)        \
    for (auto &itr : a) \
        cin >> itr;
#define WHILE(n) while (n--)

void solve()
{
    lli n;
    cin >> n;
    vector<pair<lli, lli>> coordinates;
    vector<pair<lli, lli>> tr;
    pair<lli, lli> f = {0, 0}, s = {0, 1}, t = {1, 0}, b = {1, 1};
    coordinates.pb(f);
    coordinates.pb(s);
    coordinates.pb(t);
    coordinates.pb(b);
    tr.pb(b);
    for (int i = 0; i < n; i++)
    {
        // loop until we construct n cells with 4 gray cell surrounded cells
        // each time we add on a square
        auto pr = tr.back();
        tr.push_back({pr.first + 1, pr.second + 1});
        coordinates.pb({pr.first + 1, pr.second + 1});
        coordinates.push_back({pr.first + 1, pr.second});
        coordinates.push_back({pr.first, pr.second + 1});
    }
    cout << coordinates.size() << endl;
    for (auto &itr : coordinates)
    {
        cout << itr.first << " " << itr.second << endl;
    }
}

int main()
{
    needforspeed;
    lli t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}