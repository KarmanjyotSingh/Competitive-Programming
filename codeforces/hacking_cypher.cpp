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

lli a, b;
string s;
lli lsum = 0;
bool check(lli itr)
{
    lsum = ((lsum % a) * (10 % a)) % a + (s[itr - 1] - '0') % a;
    // lsum %= a;

    return lsum % a == 0;
}
bool check1(lli itr)
{
    // checks if the left part is divisible by a or not
    // if passed itr , check to the left of itr
    lli pow = 1;
    lli sum = 0;
    for (lli i = s.length() - 1; i >= itr; i--)
    {
        sum = sum % b + (pow * (s[i] - '0') % b) % b;
        pow = (pow % b * 10 % b) % b;
    }
    return sum % b == 0;
}
void solve()
{
    cin >> s;
    cin >> a >> b;
    // lsum = s[0] - '0';

    vector<lli> suff(s.length());
    lli n = s.length();
    suff[n - 1] = (s[n - 1] - '0') % b;
    lli pow = 10;
    for (lli i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] % b + (((s[i] - '0') % b) * pow) % b;

        pow = ((pow % b) * (10 % b)) % b;
    }
    for (lli i = 1; i < s.length(); i++)
    {

        if (check(i) && suff[i] % b == 0)
        {
            if (s[i] == '0')
                continue;
            cout << "YES" << endl;
            cout << s.substr(0, i) << endl
                 << s.substr(i, s.length()) << endl;
            ;
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
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