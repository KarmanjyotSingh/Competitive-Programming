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
vector<vector<lli>> graph(20020);
vector<bool> visited(20020, false);
lli dfs(lli node)
{
    visited[node] = true;
    lli cnt = 0;
    lli l, r = -1;
    if (graph[node].size() == 1)
    {
        return 1 + dfs(graph[node][0]);
    }
    else if (graph[node].size() == 2)
    {
        l = dfs(graph[node][0]);
        r = dfs(graph[node][1]);
        return 1 + MAX(l, r);
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    if (m <= n)
    {
        cout << n - m << endl;
        return;
    }
    queue<lli> q;
    q.push(n);
    lli a, b;
    while (!q.empty())
    {
        lli main = q.front();
        q.pop();
        if (main == m)
            break;
        if (main > 0)
        {
            q.push(main - 1);
            a = main - 1;
            graph[main].push_back(main - 1);
        }
        if (main < m)
        {
            q.push(main * 2);
            b = 2 * main;
            graph[main].push_back(main * 2);
        }
        if (a == m || b == m)
            break;
    }
    // for (auto i = 0; i < graph.size(); i++)
    // {
    //     if (graph[i].size() == 0)
    //         continue;
    //     cout << "parent : " << i << endl;
    //     for (auto j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dfs(n) << endl;
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