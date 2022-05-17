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
    string s;
    cin >> s;
    lli rem = 0;
    lli n = s.length(), pow = 1;
    for (auto i = n - 1; i >= 0; i--)
    {
        rem = (rem % 8) + (pow * (s[i] - '0') % 8) % 8;
        pow = ((pow % 8) * 2) % 8;
    }
    if (rem % 8 == 0)
    {
        cout << "YES" << endl
             << s << endl;
    }
    vector<lli> pref, suff(n);
    pow = 1;
    lli lsum = 0;
    lli a = 8;
    pref.push_back(0);
    for (int i = 0; i < n; i++)
    {
        lsum = ((lsum % a) * (10 % a)) % a + (s[i] - '0') % a;
        pref.push_back(lsum % 8);
    }
    suff[n - 1] = 0;
    pow = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        lli rem = (suff[i + 1] % 8) + (pow * (s[i + 1] - '0') % 8) % 8;
        pow = ((pow % 8) * 2) % 8;
        suff[i] = rem;
    }

    for (int i = 0; i < n; i++)
    {
    }
    cout << "NO" << endl;
}
// 11 3 1 4 2 7 8 5 6 11 10 9 
// 11 1 10 5 9 9 3 5 6 6 2 8 

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