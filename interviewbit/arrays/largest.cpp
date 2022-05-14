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
// int compare(lli a, lli b) { return a > b; }
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
bool is_prefix(string a, string b)
{
    // check if b is prefix of A
    int n = a.length(), m = b.length();
    if (m > n)
        return false;

    for (auto i = 0; i < m; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int compare(int a, int b)
{
    if (a == b)
        return 1;
    string sa = to_string(a), sb = to_string(b);
    int la = sa.length(), lb = sb.length();
    if (is_prefix(sa, sb))
    {
        // sb is prefix of sa => la > lb
        if (sa[0] >= sa[lb])
            return 1;
        return 0;
    }
    else if (is_prefix(sb, sa))
    {
        // sa is prefix of sb
        if (sb[0] >= sb[la])
            return 1;
        return 0;
    }
    return a < b;
    // retu
}
void solve()
{
    string s;
    // s.c_str
    lli n;
    cin >> n;
    // int n = A.size();
    vector<int> A(n);
    for (auto &itr : A)
        cin >> itr;
    vector<vector<int>> vec(10);
    for (auto i = 0; i < n; i++)
    {
        int lg = (int)log10(A[i]);
        int power = (int)pow(10, lg);
        vec[(int)A[i] / power].push_back(A[i]);
    }
    for (auto &itr : vec)
    {
        sort(itr.begin(), itr.end(), compare);
    }
    int k = 0;
    for (auto i : vec[1])
    {

        cout << i << " ";
        k++;
    }

    for (auto i = 9; i >= 0; i--)
    {
        if (vec[i].empty())
            continue;
        else
        {
            for (int j = vec[i].size() - 1; j >= 0; j--)
            {
                s += to_string(vec[i][j]);
            }
        }
    }
    cout << s << endl;
    s = &s[3];
    // cout << s << endl;
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