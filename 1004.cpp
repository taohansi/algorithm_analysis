#include <iostream>
using namespace std;
int a[1000];
int b[1000];
int n;
int label;
void merge(int l, int m, int h)
{
    int i = l, j = m + 1;
    for (int k = l; k <= h; k++)
        b[k] = a[k];
    for (int k = l; k <= h; k++)
    {
        if (i > m)
            a[k] = b[j++];
        else if (j > h)
            a[k] = b[i++];
        else if (b[i] < b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
}
void merge_sort(int l, int h, int c) //[l,h]
{
    if (h <= l)
        return;
    int m = (l + h) / 2;
    merge_sort(l, m, c + 1);
    merge_sort(m + 1, h, c + 1);
    merge(l, m, h);
    if (c == 3)
    {   // warning! just print every sorted node rahter than the entire array (because the recursion sequence i.e. the node visited sequence)
        for (int i = l; i <= h; i++)
        {
            if (i == n - 1)
                cout << a[i] << endl;
            else
                cout << a[i] << " ";
        }
    }
}
// void merge_sort(int l, int h, int c)
// {
//     for (int len = 1; len < n; len *= 2)
//     {
//         for (int i = 0; i < n; i += len * 2)
//         {
//             merge(i, i + len - 1, min(i + len + len - 1, n-1));
//         }
//     }
// }
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        merge_sort(0, n - 1, 1);
        // for (int i = 0; i < n - 1; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << a[n - 1] << endl;
    }
}