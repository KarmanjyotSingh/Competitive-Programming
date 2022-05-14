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
    multiset<lli> attack_x, attack_y;
    cin >> n >> q;
    lli type;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            lli x, y;
            cin >> x >> y;
            attack_x.insert(x);
            attack_y.insert(y);
        }
        else if (type == 2)
        {
            lli x, y;
            cin >> x >> y;
            attack_x.erase(attack_x.lower_bound(x));
            attack_y.erase(attack_y.lower_bound(y));
        }
        else
        {
            lli a, b, c, d;
            cin >> a >> b >> c >> d;
            bool f1 = true, f2 = true;
            for (auto i = a; i <= c; i++)
            {
                if (attack_x.find(i) != attack_x.end())
                    continue;
                else
                {
                    f1 = false;
                    break;
                }
            }
            for (auto i = b; i <= d; i++)
            {
                if (attack_y.find(i) != attack_y.end())
                    continue;
                else
                {
                    f2 = false;
                    break;
                }
            }
            if (f1 || f2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
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