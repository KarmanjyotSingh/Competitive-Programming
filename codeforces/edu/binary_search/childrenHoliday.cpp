#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
lli n, m;
vector<lli> t, z, y;
vector<lli> d;
bool good(lli mid)
{
    lli cnt = 0;

    for (lli i = 0; i < n; i++)
    {
        cnt = cnt + (d[i] * mid / (t[i]));
    }

    return cnt >= m;
}
int main()
{
    cin >> m >> n;
    if (m == 0)
    {
        return 0;
    }
    lli mx = LONG_LONG_MIN;
    for (auto i = 0; i < n; i++)
    {
        lli a, b, c;
        cin >> a >> b >> c;
        t.push_back(a);
        z.push_back(b);
        y.push_back(c);
        d.push_back(a * b + c);
        mx = max(mx, a * b + c);
    }
    lli l = 0, r = 1e10;

    while (l + 1 < r)
    {
        lli mid = l + (r - l) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;

    for (int i = 0; i < n; i++)
    {
        cout << r*(d[i]/t[i])<< " ";
    }

    return 0;
}
