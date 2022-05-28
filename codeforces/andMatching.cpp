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
    lli l = 0, r = n - 1;
    vector<pair<lli, lli>> ans;
    while (l < r)
    {
        ans.pb({l, r});
        l++;
        r--;
    }
    if (k == n - 1 && n <= 4)
        cout << -1 << endl;
    else if (k == n - 1)
    {
        bool one = false, two = false;
        for (auto i = 0; i < ans.size(); i++)
        {
            lli o = ans[i].first;
            lli e = ans[i].second;
            if (o == n - 2)
            {
                ans[0].first = o;
                ans[1].second = n - 3;
                ans[2].second = 0;
                break;
            }
            else if (e == n - 2)
            {
                ans[0].first = e;
                ans[1].second = n - 3;
                ans[2].second = 0;
                break;
            }
        }
        // we have n-2 , n-1
        // 1 , 0
        // need to swap

        for (auto &itr : ans)
            cout << itr.first << " " << itr.second << endl;
    }
    else if (k == 0)
    {
        for (auto &itr : ans)
            cout << itr.first << " " << itr.second << endl;
    }
    else
    {
        for (auto i = 0; i < ans.size(); i++)
        {
            lli o = ans[i].first;
            lli e = ans[i].second;
            if (o == k)
            {
                ans[0].first = o;
                ans[i].first = 0;
                break;
            }
            else if (e == k)
            {
                ans[0].first = e;
                ans[i].second = 0;
                break;
            }
        }
        for (auto &itr : ans)
            cout << itr.first << " " << itr.second << endl;
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