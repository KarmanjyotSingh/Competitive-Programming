int ABD(int x,int y)
{
    if(x>y)return x-y;
 else return y-x;
}
int min(int x , int y )
{
    return x < y;
}
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> points;
    for(auto  i=0;i<A.size();i++)
    points.push_back({A[i],B[i]});
    int steps =0;
    for(auto i =0;i<points.size()-1;i++)
    {
        auto p1 = points[i];
        auto p2 = points[i+1];
        auto dx = ABD(p1.first,p2.first);
        auto dy = ABD(p1.second,p2.second);
        if(dx == dy)
        {
            steps+=dx;
        }
        else if (min(dx,dy))
        {
            // dx is less , move diagnoally dx steps 
            steps+=(dx + ABD(dx,dy));
        }
        else {
            steps +=(dy + ABD(dx,dy));
        }
    }
    return steps;

}
