#include <bits/stdc++.h>
using namespace std;
typedef double lli;
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
bool good(vector<lli> &x, vector<lli> &v, lli m)
{
    // need to check if the intervals intersect or not
    // m is the time
    bool intersect = true;
    // vector<pair<lli, lli>> pa;
    lli n = x.size();
    lli l = LONG_LONG_MIN, r = LONG_MAX;
    for (auto i = 0; i < n; i++)
    {
        lli l1 = x[i] - m * v[i], r1 = x[i] + m * v[i];
        // pa.push_back({l1, r1});
        l = MAX(l, l1);
        r = MIN(r, r1);
    }
    // sort(all(pa));
    return l <= r;
}
void solve()
{
    long long int n;
    cin >> n;
    vector<lli> x(n), v(n);
    for (auto i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    double l = 0, r = 1e10;
    while (r - l > 1e-6)
    {
        double mid = l + (r - l) / 2.0;
        if (good(x, v, mid))
            r = mid;
        else
            l = mid;
    }
    cout << setprecision(10) << r << endl;
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