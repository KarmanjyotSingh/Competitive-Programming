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
string mul(string a, lli d)
{
    string ans = "";
    int carry = 0;
    reverse(all(a));
    for (int i = 0; i < a.size(); i++)
    {
        int cur = (a[i] - '0') * d + carry;
        carry = cur / 10;
        cur %= 10;
        ans += cur + '0';
    }
    if (carry)
        ans += carry + '0';
    reverse(all(ans));
    return ans;
}
map<string, lli> m;
lli steps(string str, lli n)
{
    if (n <= str.size())
        return 0;
    else if (m.find(str) != m.end())
        return m[str];
    lli ans = LONG_LONG_MAX;
    for (auto itr : str)
    {
        if (itr - '0' > 1)
        {
            string xx = mul(str, (lli)(itr - '0'));
            ans = MIN(ans, steps(xx, n) + 1);
        }
    }

    m[str] = ans;

    return ans;
}
void solve()
{
    lli n;
    lli x;
    cin >> n >> x;
    string s = to_string(x);
    lli ans = steps(s, n);
    if (ans == LONG_LONG_MAX)
        cout << -1 << endl;
    else
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