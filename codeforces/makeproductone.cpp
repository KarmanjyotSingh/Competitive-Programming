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
    lli n;
    cin >> n;
    lli pos = 0, neg = 0, zer = 0, x;
    vector<lli> a(n);
    lli max_neg = 1;
    for (auto i = 0; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        if (x == 0)
            zer++;
        else if (x > 0)
            pos++;
        else
        {
            neg++;
            max_neg = MAX(max_neg, x);
        }
    }
    lli ans = 0;
    for (auto i = 0; i < n; i++)
    {
        ans += MIN(ABS(a[i] - 1), ABS(a[i] + 1));
    }
    if (neg % 2 == 1 && zer == 0)
    {
        ans += 2;
    }
    cout << ans << endl;
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