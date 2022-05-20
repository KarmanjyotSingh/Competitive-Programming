#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
lli n, x, y;
bool good(lli m)
{
    // lli mn = MIN(x, y);
    lli z = ((m) / x) + ((m) / y);
    return z >= n - 1;
}
int main()
{

    cin >> n >> x >> y;
    if (n == 1)
        cout << min(x, y);
    else
    {
        lli l = 0, r = 1e10;
        while (l + 1 < r)
        {
            lli mid = l + (r - l) / 2;
            if (good(mid))
                r = MIN(r, mid);
            else
                l = mid;
        }
        cout << r + min(x, y) << endl;
    }
    return 0;
}
