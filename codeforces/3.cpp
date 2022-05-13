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
    // MAX(cost is 0's left or 1 removed)
    // minimize cost
    string s;
    cin >> s;
    // size of string
    lli n = s.size();
    // count of one
    lli one = count(all(s), '1');
    // count of zero
    lli zero = s.size() - one;
    vector<lli> arr(n + 1, 0);
    for (auto i = 0; i < n; i++)
    {
        if (s[i] == '1')
            arr[i + 1] = arr[i];
        else if (s[i] == '0')
            arr[i + 1] = arr[i] + 1;
    }
    // maximum cost , all zero are left
    lli ans = zero;
    for (int i = 0; i + one < n + 1; i++)
    {
        ans = MIN(ans, arr[i + one] - arr[i]);
    }
    cout << ans << endl;
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