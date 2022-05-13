#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A(1);
    for (auto &itr : A)
        cin >> itr;
    int itr = A.size() - 1;
    vector<int> ans;
    bool add = true;
    while (itr >= 0)
    {
        cout << itr << endl;
        if (itr < 0)
            break;
        if (add && A[itr] < 9)
        {
            ans.push_back(A[itr] + 1);
            add = false;
        }
        else
        {
            // A[itr] == 9
            if (add)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(A[itr]);
            }
        }
        itr--;
    }
    if (add)
        ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (auto itr : ans)
        cout << itr << " ";
    cout << endl;
}