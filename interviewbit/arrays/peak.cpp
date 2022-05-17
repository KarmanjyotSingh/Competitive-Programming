#include <bits/stdc++.h>
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
    vector<lli> a(n);
    input(a);
    vector<lli> pre, suff(n);
    pre.push_back(a[0]);
    set<lli> c;
    for (auto i = 1; i < n; i++)
    {
        if (pre[i - 1] == a[i])
            c.insert(i);
        pre.push_back(MAX(pre[i - 1], a[i]));
    }

    int cnt = 0;
    cnt = 0;
    cout << endl;
    suff[n - 1] = a[n - 1];
    set<lli> b;
    for (auto i = n - 2; i >= 0; i--)
    {
        if (suff[i + 1] == a[i])
            b.insert(i);
        suff[i] = MIN(suff[i + 1], a[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (c.find(i) != c.end() || b.find(i) != b.end())
        {
            continue;
        }
        else if (pre[i] == a[i] && suff[i] == a[i])
        {
            
            return;
        }
    }
   
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