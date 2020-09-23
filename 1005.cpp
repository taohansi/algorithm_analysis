#include <iostream>
using namespace std;
int a[1000];
int n;
int partition(int l, int h)
{
    int v = a[l];
    int i = l, j = h + 1;
    while (true)
    {
        while (a[++i] < v) { if(i == h) break; }
        while (a[--j] > v) { if(j == l) break; }
        if(i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}
void qucik_sort(int l, int h, int c)
{
    if (l >= h)
        return;
    int j = partition(l, h);
    qucik_sort(l, j - 1, c+1);
    qucik_sort(j + 1, h, c+1);
    if (c==2)
    {
        for (int i = l; i < h; i++)
        {
            if (i==n-1)
                cout<<a[i]<<endl;
            else
                cout<<a[i]<<" ";
        }

    }

}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        qucik_sort(0, n-1, 1);
        // for (int i = 0; i < n-1; i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<a[n-1]<<endl;

    }
}