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
vector<vector<lli>> graph(4010);
set<lli> parent;
string s;
lli dfs(vector<bool> &visited, lli node, vector<lli> &cnt)
{
    visited[node] = true;
    if (s[node] == 'W')
        cnt[node] = 1;
    else
        cnt[node] = -1;
    for (lli i = 0; i < graph[node].size(); i++)
    {
        if (!visited[graph[node][i]])
        {
            cnt[node] += dfs(visited, graph[node][i], cnt);
        }
    }
    return cnt[node];
}
void solve()
{
    for (auto i = 0; i < graph.size(); i++)
        graph[i].clear();
    parent.clear();
    lli n;
    cin >> n;
    vector<lli> a(n);
    vector<bool> visited(n, false);

    parent.insert(0);
    for (auto i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        graph[a[i]].push_back(i);
        parent.insert(a[i]);
    }

    cin >> s;
    vector<lli> cnt(n);
    cnt[0] = dfs(visited, 0, cnt);
    cout << count(all(cnt), 0) << endl;
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