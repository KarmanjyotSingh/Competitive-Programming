// solution to https://www.interviewbit.com/problems/pick-from-both-sides/
int MAX(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int Solution::solve(vector<int> &A, int B)
{
    vector<int> prefix, suffix;
    prefix.push_back(0);
    // one element is selected
    prefix.push_back(A[0]);
    int n = A.size();
    for (auto i = 1; i < n; i++)
        prefix.push_back(prefix[i] + A[i]);

    suffix.push_back(0);
    // take the last element from the Aay
    suffix.push_back(A[n - 1]);

    // suffix.push_back(prefix[n]);
    for (auto i = 1; i < n; i++)
    {
        suffix.push_back(suffix[i] + A[n - i - 1]);
    }

    int max = INT_MIN;
    for (auto i = 0; i < B + 1; i++)
        max = MAX(max, prefix[i] + suffix[B - i]);

    return max;
}
