#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (auto &itr : a)
    {
        cin >> itr;
    }
    double l = 0, r = 1e8;

    // take more and more iterations to go closer to the answer
    for (auto itr = 0; itr < 1000; itr++)
    {
        double mid = l + (r - l) / 2;
        // if mid is possible search in right
        lli cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt = cnt + (lli)floor((a[i] / mid));
        }
        if (cnt >= k)
        {
            l = mid;
        }
        else
            r = mid;
    }
    cout << setprecision(20) << l << endl;

    return 0;
}