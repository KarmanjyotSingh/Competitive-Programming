// For the previous solution , I got a  TLEL perhaps
// due to the time consuming O(n) for loop for checking the map count
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
#define MAXN 100010
int n, tree[4 * MAXN], treey[4 * MAXN];

void build(int a[])
{
    for (int i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (int i = n - 1; i > 0; --i)
        tree[i] = (tree[2 * i] + tree[2 * i + 1]);
}

void update(int p, int value)
{
    tree[p + n] = value;
    p = p + n;

    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = (tree[i] + tree[i ^ 1]);
}
int query(int l, int r)
{
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = (res + tree[l++]);

        if (r & 1)
            res = (tree[--r] + res);
    }
    return res;
}

void buildy(int a[])
{
    for (int i = 0; i < n; i++)
        treey[n + i] = a[i];
    for (int i = n - 1; i > 0; --i)
        treey[i] = (treey[2 * i] + treey[2 * i + 1]);
}

void updatey(int p, int value)
{
    treey[p + n] = value;
    p = p + n;

    for (int i = p; i > 1; i >>= 1)
        treey[i >> 1] = (treey[i] + treey[i ^ 1]);
}
int queryy(int l, int r)
{
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = (res + treey[l++]);

        if (r & 1)
            res = (treey[--r] + res);
    }
    return res;
}

void solve()
{
    lli q;
    cin >> n >> q;
    lli t;
    vector<lli> mapx(n + 1, 0), mapy(n + 1, 0);
    int a[n] = {}, b[n] = {};
    build(a);
    buildy(b);

    while (q--)
    {
        cin >> t;
        if (t == 1)
        {
            lli x, y;
            cin >> x >> y;
            mapx[x]++;
            mapy[y]++;
            update(x - 1, 1);
            updatey(y - 1, 1);
        }
        else if (t == 2)
        {
            lli x, y;
            cin >> x >> y;
            mapx[x]--;
            if (mapx[x] == 0)
                update(x - 1, 0);
            mapy[y]--;
            if (mapy[y] == 0)
                updatey(y - 1, 0);
        }
        else
        {
            lli x, y, a, b;
            cin >> x >> y >> a >> b;
            auto c = query(x - 1, a);
            auto d = queryy(y - 1, b);
            bool flag = (c == a - x + 1) || (d == b - y + 1);
            if (flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
int main()
{
    needforspeed;
    lli t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}