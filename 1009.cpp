#include <bits/stdc++.h>
using namespace std;
int d[100];
int a[100];
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int p = 0;
        memset(d, 127, sizeof(d));
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= d[p])
            {
                d[++p] = a[i];
            }
            else
            {
                *upper_bound(d + 1, d + p + 1, a[i], greater<int>()) = a[i];
            }
        }
        // for (int i = 0; i < p; i++)
        // {
        //     cout<<"d "<<d[i]<< " ";
        // }

        cout << p << endl;
    }
}