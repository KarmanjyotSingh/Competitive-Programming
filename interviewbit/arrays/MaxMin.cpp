int Solution::solve(vector<int> &A) {
    int max = INT_MIN , min = INT_MAX;
    for(int i = 0 ; i <A.size();i++)
    {
        if(min>A[i])
        min=A[i];
        if(max<A[i])
        max=A[i];
    }
    return max + min;
}
