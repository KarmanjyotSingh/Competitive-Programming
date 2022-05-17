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
    vector<char> a;
    a.push_back('V');
    a.push_back('I');
    a.push_back('B');
    a.push_back('G');
    a.push_back('Y');
    a.push_back('O');
    a.push_back('R');
    lli t = n / 7, r = n % 7;
    int i = 0;
    while (t--)
    {
        cout << "VIBGYOR";
        }
    if (r == 1)
    {
        cout << "G" << endl;
    }
    else if (r == 2)
    {
        cout << "BY" << endl;
    }
    else if (r == 3)
    {
        cout << "GYO" << endl;
    }
    else if (r == 4)
    {
        cout << "VIBG" << endl;
    }
    else if (r == 5)
    {
        cout << "VIBGY" << endl;
    }
    else if (r == 6)
    {
        cout << "VIBGYO" << endl;
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

