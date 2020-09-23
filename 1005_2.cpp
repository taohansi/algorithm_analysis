#include <iostream>
using namespace std;
int a[1000];
int n;
int x_i;
int f;
int partition(int l, int h)
{
    int v = a[l];
    int p = l;
    int i = l;
    while (true)
    {
        while((a[++i] >= v)) { if(i>h) break; }
        if(i>h) break;
        swap(a[++p], a[i]);
    }
    swap(a[p], a[l]);
    return p;
}
void qucik_sort(int l, int h, int c)
{
    if (l >= h)
        return;
    int j = partition(l, h);
    if (c==2)
    {
        for (int i = l; i <= h; i++)
        {
            if (i==n-1)
                cout<<a[i]<<endl;
            else
                cout<<a[i]<<" ";
        }
        if (f==0)
        {
            if (x_i==n-1)
                cout<<a[x_i]<<endl;
            else
                cout<<a[x_i]<<" ";
            f = 1;
        }

    }
    if (c == 1)
    {
        x_i = j;
    }

    qucik_sort(l, j - 1, c+1);
    qucik_sort(j + 1, h, c+1);
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
        f = 0;
        // for (int i = 0; i < n-1; i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<a[n-1]<<endl;

    }
}