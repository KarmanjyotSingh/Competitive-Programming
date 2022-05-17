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
// dfs
vector<lli> path;
void dfs(vector<vector<lli>> &graph, lli node, vector<bool> &visited)
{
    visited[node] = true;
    if (graph[node].empty())
    {
        cout << path.size() << endl;
        for (auto itr : path)
            cout << itr + 1 << " ";
        cout << endl;
        path.clear();
    }
    for (lli i = 0; i < graph[node].size(); i++)
    {
        path.push_back(graph[node][i]);
        if (!visited[graph[node][i]])
            dfs(graph, graph[node][i], visited);
    }
}
void solve()
{
    lli n;
    cin >> n;
    vector<lli> p(n);
    path.clear();
    lli i = 0,
        root;
    vector<vector<lli>> graph(n);
    vector<bool> visited(n, false);

    for (auto &itr : p)
    {
        cin >> itr;
        if (i == itr - 1)
            root = i;
        else
            graph[itr - 1].push_back(i);
        i++;
    }
    lli ans = 0;
    for (auto i = 0; i < n; i++)
    {
        if (graph[i].empty())
            ans++;
    }
    cout << ans << endl;
    path.push_back(root);
    dfs(graph, root, visited);
    //  ans will always be equal to the number of leaf nodes
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