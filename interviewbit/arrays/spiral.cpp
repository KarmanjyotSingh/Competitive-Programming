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
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(8);
    A.push_back(9);
    int B = 9, C = 1;
    vector<vector<int>> spiral(B);
    int n = A.size();
    // bxc matrix , b rows anc C columns ye
    int t = 0, itr = 0, i = 0, j = 0, addi = 0, addj = 1;
    for (auto itr = 0; itr < B; itr++)
    {
        for (auto i = 0; i < C; i++)
            spiral[itr].push_back(0);
    }
    int flag = 1;
    int u = 0, l = 0, r = C - 1, d = B - 1;
    if (C > 1)
        while (t != n)
        {
            spiral[i][j] = A[t];
            if (flag == 1)
            {
                j++;
                if (j == r)
                {
                    flag = 2;
                    u++;
                }
            }
            else if (flag == 2)
            {
                i++;
                if (i == d)
                {
                    r--;
                    flag = 3;
                }
            }
            else if (flag == 3)
            {
                j--;
                if (j == l)
                {
                    flag = 4;
                    d--;
                }
            }
            else if (flag == 4)
            {
                i--;
                if (i == u)
                {
                    flag = 1;
                    l++;
                }
            }
            t++;
        }
    else
    {
        for (int i = 0; i < n; i++)
            spiral[i][0] = A[i];
    }
    for (auto i = 0; i < B; i++)
    {
        for (auto j = 0; j < C; j++)
        {
            cout << spiral[i][j] << " ";
        }
        cout << endl;
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