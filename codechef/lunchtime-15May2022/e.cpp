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
lli n, m;

lli pmod(lli a, lli b)
{
    lli rem = (a - b) % m;
    rem = MAX(rem, m - rem) % m;
    return a + b + rem;
}
void solve()
{
    cin >> n >> m;
    vector<lli> a(n);
    map<lli, lli> mp;
    for (auto &itr : a)
    {
        cin >> itr;
        mp[itr]++;
    }
    lli f = -1, s = -1;
    for (auto i = 0; i < n; i++)
    {
        if (a[i] - 1 >= 0 && (mp[a[i]] > 0 && mp[a[i] - 1] > 0))
        {
            f = MAX(f, a[i]);
            s = MAX(s, a[i] - 1);
        }
        if ((mp[a[i]] > 0 && mp[a[i] + 1] > 0))
        {
            f = MAX(f, a[i]);
            s = MAX(s, a[i] + 1);
        }
    }
    lli val = -1;
    if (f != -1 && s != -1)
        val = pmod(f, s);
    lli ans = LONG_LONG_MIN;
    sort(all(a));
    lli min = a[0], max = a[n - 1], i = n - 1;
    while (i >= 0 && a[i] == max)
        i--;
    lli b = (i > 0) ? a[i] : max;
    i = 0;
    while (i < n && a[i] == min)
        i++;
    lli c;

    if (i == n)
        c = min;
    else
        c = a[i];
    cout << MAX(val, MAX(pmod(min, c), MAX(pmod(max, min), pmod(max, b)))) << endl;
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