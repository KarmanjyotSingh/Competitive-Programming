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
    vector<lli> vec(n);
    lli sum = 0;
    for (auto &itr : vec)
    {
        cin >> itr;
        sum += itr;
    }
    lli x, y, z;
    vector<bool> flag(n, true);
    bool all = false;
    lli last;
    vector<lli> a;
    set<lli> idx;
    for (auto i = 0; i < n; i++)
        idx.insert(i);
    lli az = 0;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            auto it = idx.find(y - 1);
            if (it != idx.end())
            {
                sum = sum - vec[y - 1] + z;
                vec[y - 1] = z;
            }
            else
            {
                idx.insert(y - 1);
                sum = sum - az + z;
                vec[y - 1] = z;
            }
        }
        else
        {
            cin >> z;
            sum = n * z;
            az = z;
            idx.clear();
        }
        cout << sum << endl;
    }
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