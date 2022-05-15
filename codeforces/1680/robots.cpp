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
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
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
    lli n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &itr : s)
        cin >> itr;
    if (s[0][0] == 'R')
    {
        cout << "YES" << endl;
        return;
    }
    vector<pair<lli, lli>> pos;
    lli u = LONG_LONG_MAX, d = LONG_LONG_MAX, l = LONG_LONG_MAX, r = LONG_LONG_MAX;
    for (auto row = 0; row < n; row++)
    {
        for (auto col = 0; col < m; col++)
        {
            if (s[row][col] == 'R')
            {
                u = MIN(u, ABD(0, row));
                d = MIN(d, ABD(n - 1, row));
                l = MIN(l, ABD(0, col));
                r = MIN(r, ABD(m - 1, col));
                pos.push_back({row, col});
            }
        }
    }
    // cout << "u " << u << " l " << l << endl;
    bool can = false;
    for (auto posi : pos)
    {
        // cout << posi.first << " " << posi.second << endl;
        lli x = posi.first - 0;
        lli y = posi.second - 0;
        if (x <= u && y <= l)
        {
            can = true;
            break;
        }
    }
    if (can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    needforspeed;
    lli t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}