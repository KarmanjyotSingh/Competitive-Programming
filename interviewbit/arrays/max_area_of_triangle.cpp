
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABD(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int Solution::solve(vector<string> &a) {
//to maximize area , choose vertex in same row and the farthest , and choose the other one 


vector<vector<int>> r(a[0].size()), b(a[0].size()), g(a[0].size());
    
    for (auto i = 0; i < a.size(); i++)
    {
        for (auto itr = 0; itr < a[i].size(); itr++)
        {
            auto ch = a[i][itr];
            if (ch == 'r')
                r[itr].push_back(i);
            else if (ch == 'g')
                g[itr].push_back(i);
            else
                b[itr].push_back(i);
        }
    }

    float max = 0;
    int m = a[0].size();

    for (auto i = 0; i < m; i++)
    {
        sort(r[i].begin(), r[i].end());
        sort(g[i].begin(), g[i].end());
        sort(b[i].begin(), b[i].end());
        bool rg = r[i].size() && g[i].size();
        bool rb = r[i].size() && b[i].size();
        bool gb = g[i].size() && b[i].size();

        if (rg)
        {
            // cout << 1 << endl;
            for (auto j = m - 1; j >= 0; j--)
            {
                if (!b[j].empty())
                {
                    float area = (float)0.5 * (float)MAX(ABD(r[i][0], g[i].back()) + 1, ABD(g[i][0], r[i].back()) + 1);
                    auto height = ABD(j, i) + 1;
                    max = MAX((float)height * area, max);
                }
            }
        }
        if (rb)
        {
            // cout << 2 << endl;
            for (auto j = m - 1; j >= 0; j--)
            {
                if (!g[j].empty())
                {
                    float area = (float)0.5 * (float)MAX(ABD(r[i][0], b[i].back()) + 1, ABD(b[i][0], r[i].back()) + 1);
                    auto height = ABD(j, i) + 1;
                    max = MAX((float)height * area, max);
                    // cout << "j " << j << " i " << i << " area " << area << " height " << height << " max " << max << endl;
                }
            }
        }
        if (gb)
        {
            // cout << 3 << endl;
            for (auto j = m - 1; j >= 0; j--)
            {
                if (!r[j].empty())
                {
                    float area = (float)0.5 * (float)MAX(ABD(g[i][0], b[i].back()) + 1, ABD(b[i][0], g[i].back()) + 1);
                    auto height = ABD(j, i) + 1;
                    max = MAX((float)height * area, max);
                }
            }
        }
    }
    // cout << max << endl;
    return ceil(max);

    // return max;

}

