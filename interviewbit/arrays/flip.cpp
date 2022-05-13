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
    vector<int> ans;
    vector<int> pref;
    vector<int> pos;

    if (s[0] == '1')
        pref.push_back(1);
    else
    {
        pref.push_back(0);
        pos.push_back(0);
    }
    for (auto i = 1; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            pref.push_back(pref[i - 1] + 1);
        }
        else
        {
            pref.push_back(pref[i - 1]);
            pos.push_back(i);
        }
    }
    int i = 0, j = pos.size() - 1;
    int l = pos[0], r = pos.back();
    while (i <= j)
    {
        int num_one = pref[r] - pref[l];
        int len = j - i;
        
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