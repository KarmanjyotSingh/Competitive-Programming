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
    lli n, k;
    cin >> n >> k;
    if (k % 2 == 0 && n % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    bool possible = false;
    if (n % 2 == 1 && n >= k)
    {
        // only odd numbers would work
        possible = true;
        cout << "YES" << endl;

        lli ct = k - 1;
        while (ct--)
            cout << 1 << " ";
        cout << n - (k - 1) << endl;
    }
    if (!possible && n % 2 == 0 && k % 2 == 0 && n >= k)
    {
        possible = true;
        cout << "YES" << endl;

        lli ct = k - 1;
        while (ct--)
            cout << 1 << " ";
        cout << n - (k - 1) << endl;
    }
    if (!possible && n % 2 == 0 && n >= 2 * k)
    {
        // only evens would work
        possible = true;
        cout << "YES" << endl;

        lli ct = k - 1;
        while (ct--)
            cout << 2 << " ";
        cout << n - 2 * (k - 1) << endl;
    }

    if (!possible)
        cout << "NO" << endl;
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