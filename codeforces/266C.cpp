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
    string s;
    // s.length
    lli n;
    cin >> n;
    vector<lli> vec(n);
    vector<lli> cnt(n+100, 0);
    lli sum = 0;
    for (auto &itr : vec)
    {

        cin >> itr;
        sum += itr;
    }
    if (sum % 3 != 0)
        cout << 0 << endl;
    else
    {
        sum /= 3;
        lli h = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            h += vec[i];
            if (h == sum)
            {
                cnt[i] = 1;
            }
        }
        for (auto i = n - 2; i >= 0; i--)
        {
            cnt[i] += cnt[i + 1];
        }
        long long ans = 0;
        h = 0;
        for (int i = 0; i < n; i++)
        {
            h += vec[i];
            if (h == sum)
            {
                ans += cnt[i + 2];
            }
        }
        cout << ans << endl;
    }
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