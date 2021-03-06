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
    vector<lli> pref, suff;
    lli cnt = 0;
    for (auto itr : s)
    {
        int x = itr - '0';
        if (!x)
            cnt++;
        else
            pref.push_back(cnt);
    }
    pref.push_back(cnt);
    cnt = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int x = s[i] - '0';
        if (!x)
            cnt++;
        else
            suff.push_back(cnt);
    }
    suff.push_back(cnt);
    lli zero = count(all(s), '0');
    lli one = s.length() - zero;
    lli left = -1, right = s.length();
    lli ans = right;
    while (left <= right)
    {
        lli mid = left + (right - left) / 2;
        bool possible = false;

        for (auto i = 0; i <= mid; i++)
        {
            lli left = zero;
            left = left - (pref[i] + suff[mid - i]);
            if (left <= mid)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            ans = MIN(mid, ans);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
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