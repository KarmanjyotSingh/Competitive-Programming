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
    if (n % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        int f = n % 4, s = n % 6;
        // find a + b such that 4a +6b = n
        if (n < 4 || (f == 1 || f == 3))
        {
            cout << -1 << endl;
            return;
        }
        else if (!f && !s)
        {
            cout << n / 6 << " " << n / 4 << endl;
            return;
        }
        else
        {
            lli min = n / 6;
            while ((n - (6 * min)) % 4 != 0)
                min--;
            min += ((n - (6 * min)) / 4);
            lli max = 0;
            while ((n - (6 * max)) % 4 != 0)
                max++;
            max += ((n - 6 * max) / 4);
            cout << min << " " << max << endl;
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