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
// #define pb push_back
#define FOR (i, n) for (i = 0; i < n; i++)
#define FORR(i, n) for (i = n - 1; i >= 0; i--)
#define input(a)        \
    for (auto &itr : a) \
        cin >> itr;
#define WHILE(n) while (n--)
string st;
lli b, s, c;
lli pb, ps, pc;
lli ruble;

bool good(lli m)
{
    // check if m could be made or not
    lli cost = 0;
    lli x = count(all(st), 'B');
    lli y = count(all(st), 'S');
    lli z = count(all(st), 'C');
    x *= m;
    y *= m;
    z *= m;
    x -= b;
    y -= s;
    z -= c;
    cost = MAX(0, x) * pb + MAX(0, y) * ps + MAX(0, z) * pc;
    // cost = MIN(0, m - x) * pb + MIN(0, m - y) * ps + MIN(0, m - z) * pc;
    return cost <= ruble;
}
void solve()
{
    cin >> st;
    cin >> b >> s >> c;
    cin >> pb >> ps >> pc;
    cin >> ruble;
    lli l = 0, r = 1e14;
    while (l + 1 < r)
    {
        lli mid = l + (r - l) / 2;
        if (good(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}

int main()
{
    needforspeed;
    lli t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}