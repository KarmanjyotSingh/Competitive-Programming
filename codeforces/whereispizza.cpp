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
typedef struct Set
{
    lli *array;
} Set;
lli Parent(lli i)
{
    return (i - 1) / 2;
}
lli LeftChild(lli i)
{
    return 2 * i + 1;
}
lli RightChild(lli i)
{
    return 2 * i + 2;
}
Set *MakeSet(lli NumNodes)
{
    Set *s = (Set *)malloc(sizeof(Set));
    NumNodes = NumNodes + 1;
    s->array = (lli *)malloc(NumNodes * sizeof(lli));
    for (int i = 1; i < NumNodes; i++)
    {
        s->array[i] = -1;
    }
    return s;
}
lli Find(Set *s, lli NumNodes, lli index)
{
    lli parent;
    if (index > NumNodes) // flag for errors
        return 0;
    while (s->array[index] > 0)
    {
        index = s->array[index];
    }
    parent = index;
    return parent;
}
void Union(Set *s, lli NumNodes, lli a, lli b)
{
    lli A = Find(s, NumNodes, a);
    lli B = Find(s, NumNodes, b);
    if (s->array[A] < s->array[B]) // A is heavier tree
    {
        s->array[A] = s->array[A] + s->array[B];
        s->array[B] = A;
    }
    else
    {
        s->array[B] = s->array[A] + s->array[B];
        s->array[A] = B;
    }
}
void solve()
{
    lli n;
    cin >> n;
    vector<lli> a(n), b(n), c(n), d(n);
    input(a);
    input(b);
    // first dorm the sets u
    input(d);
    Set *s = MakeSet(n);
    for (lli i = 0; i < n; i++)
    {
        if (Find(s, n, a[i]) != -1)
            continue;
        Union(s, n, a[i], b[i]);
        lli c = b[a[i]];
    }
}
int main()
{
    needforspeed;
    lli t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}