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
lli n, m, d;
map<pair<lli, lli>, lli> mp;
bool check(lli m, vector<vector<lli>> &graph)
{
    // need to find till only d levels in bfs
    // check if we can find a max >=m
    queue<lli> q;
    q.push(1);
    // do bfs for d levels
    lli level = 0;
    lli mxcost = LONG_LONG_MIN;
    while (!q.empty())
    {
        lli curr = q.front();
        q.pop();
        for (auto itr : graph[curr])
        {
            q.push(itr);
        }
        if (curr == n && mxcost <= m)
            return true;
    }
}
void solve()
{
    cin >> n >> m >> d;

    vector<vector<lli>> graph(n + 1);
    for (auto itr = 0; itr < m; itr++)
    {
        lli u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(v);
        mp[{u, v}] = w;
    }
    lli l = 0, r = n;
    while (l + 1 < r)
    {
        lli mid = l + (r - l) / 2;
        if (check(mid, graph))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
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