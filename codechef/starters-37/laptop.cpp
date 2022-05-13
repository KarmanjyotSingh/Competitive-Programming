#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(11, 0);
        for (auto &itr : a)
        {
            cin >> itr;
            cnt[itr]++;
        }
        int itr = 0, max = -1, maxi = -1;
        for (auto &i : cnt)
        {
            if (i > max)
            {
                max = i;
                maxi = itr;
            }
            itr++;
        }
        if (count(cnt.begin(), cnt.end(), max) != 1)
            cout << "CONFUSED" << endl;
        else
            cout << maxi << endl;
    }
    return 0;
}