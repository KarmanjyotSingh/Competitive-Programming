#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

// #define lli lli
lli _mergeSort(lli arr[], lli temp[], lli left, lli right);
lli merge(lli arr[], lli temp[], lli left, lli mid,
          lli right);
lli mergeSort(lli arr[], lli array_size)
{
    lli temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
lli _mergeSort(lli arr[], lli temp[], lli left, lli right)
{
    lli mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array llio two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
lli merge(lli arr[], lli temp[], lli left, lli mid,
          lli right)
{
    lli i, j, k;
    lli inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

void solve()
{
    lli n;
    cin >> n;
    lli a[n];
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    cout << mergeSort(a, n) << endl;
}
int main()
{
    lli t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}