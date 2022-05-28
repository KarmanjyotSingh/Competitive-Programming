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
    lli n, q;
    cin >> n >> q;
    lli type, x, t;
    vector<vector<lli>> app(n + 1);
    set<lli> unread;
    lli noti = 0;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            app[x].push_back(noti);
            unread.insert(noti);
            noti += 1;
        }
        else if (type == 2)
        {
            cin >> x;
            for (auto itr : app[x])
            {
                auto it = unread.find(itr);
                if (it != unread.end())
                {
                    unread.erase(it);
                }
            }
        }
        else
        {
            cin >> t;
            for (auto i = 0; i < t; i++)
            {
                if (unread.find(i) != unread.end())
                {
                    unread.erase(i);
                }
            }
        }
        cout<<unread.size()<<endl;
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