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

string s, t;
vector<lli> del;
bool good(lli m)
{
    // it deletes characters from the first string check if t could be formed or nit
    lli n = s.length();
    vector<bool> idx(n + 1, true);
    for (auto itr = 0; itr < m; itr++)
        idx[del[itr]] = false;

    string temp;
    for (lli i = 1; i <= n; i++)
        if (idx[i])
            temp += s[i - 1];
    lli j = 0, mi = t.length();
    for (auto i = 0; i < temp.length(); i++)
    {
        if (temp[i] == t[j])
            j++;
        if (j == mi)
            return true;
        else if (j > mi)
            return false;
    }
    return false;
}
void solve()
{

    cin >> s >> t;

    lli k = t.length();

    lli l = 0, r = s.length();
    for (auto i = 0; i < r; i++)
    {
        lli x;
        cin >> x;
        del.push_back(x);
    }
    while (l + 1 < r)
    {
        lli mid = l + (r - l) / 2;
        if (good(mid))
            l = mid;
        else
            r = mid;
    }

    cout << l << endl;
}
int main()
{
    needforspeed;
    lli te = 1;
    // cin >> t;
    while (te--)
    {
        solve();
    }
    return 0;
}