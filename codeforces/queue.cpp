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
    vector<pair<lli, lli>> a;
    lli x, y;
    lli sec, secl;
    map<lli, lli> m, ba;
    map<lli, lli> cnt;

    for (auto i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
        if (x == 0)
            sec = y;

        if (y == 0)
            secl = x;
        m[x] = y;
        ba[y] = x;
        cnt[x]++;
        cnt[y]++;
    }

    lli f = 0, l = 0;

    for (auto itr : cnt)
    {
        lli x = itr.first;
        if (itr.second == 1)
        {
            if (!f)
                f = x;
            else if (!l)
                l = x;
        }
    }
    // second element se start kro and aage propogate kro
    vector<lli> ans(n + 1, 0), ans2(n + 1, 0);

    ans[n] = f, ans2[n] = l;
    ans[1] = l, ans2[1] = f;
    ans[2] = sec, ans2[2] = sec;
    ans[n - 1] = secl, ans2[n - 1] = secl;

    // filled all the even indices
    for (auto i = 4; i <= n; i += 2)
    {
        ans[i] = m[ans[i - 2]];
        ans2[i] = m[ans2[i - 2]];
    }
    for (auto i = 3; i <= n; i += 2)
    {
        ans[i] = m[ans[i - 2]];
        ans2[i] = m[ans2[i - 2]];
    }
    if (count(all(ans2), 0) != 1)
        for (auto itr : ans)
        {
            if (itr)
                cout << itr << " ";
        }
    else
        for (auto itr : ans2)
        {
            if (itr)
                cout << itr << " ";
        }

    cout << endl;
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