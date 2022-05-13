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
    int a[n][m];

    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < m; j++)
            cin >> a[i][j];
    lli ans[n][m];
    lli max = LONG_LONG_MIN;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            ans[i][j] = a[i][j];
            int itri = i, itrj = j;
            int o = 0, e = 0, f = 0, h = 0;
            while (itri < n && itrj < m)
            {
                o = 1;
                ans[i][j] += a[itri][itrj];
                itri++;
                itrj++;
            }
            itri = i, itrj = j;
            while (itri < n && itrj >= 0)
            {
                e = 1;
                ans[i][j] += a[itri][itrj];
                itri++;
                itrj--;
            }
            itri = i, itrj = j;
            while (itri >= 0 && itrj < m)
            {
                f = 1;
                ans[i][j] += a[itri][itrj];
                itri--;
                itrj++;
            }
            itri = i, itrj = j;
            while (itri >= 0 && itrj >= 0)
            {
                h = 1;
                ans[i][j] += a[itri][itrj];
                itri--;
                itrj--;
            }
            ans[i][j] -= (e + f + h + o) * a[i][j];
            if (max < ans[i][j])
                max = ans[i][j];
        }
    }
    cout << max << endl;
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