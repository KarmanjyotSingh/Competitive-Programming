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
/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the

i-th day:

    A: Swim in the sea. Gain

ai​ points of happiness.
B: Catch bugs in the mountains. Gain
bi​ points of happiness.
C: Do homework at home. Gain

    ci​ points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
*/
void solve()
{
    lli n;
    cin >> n;
    // arr , dp[i][j] represents the happiness for that ith day and choosing the ith option
    int dp[n][3];
    for (auto i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0)
        {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        }
        else
        {
            dp[i][0] = MAX(dp[i - 1][1], dp[i - 1][2]) + a;
            dp[i][1] = MAX(dp[i - 1][0], dp[i - 1][2]) + b;
            dp[i][2] = MAX(dp[i - 1][0], dp[i - 1][1]) + c;
        }
    }
    cout << MAX(MAX(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
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