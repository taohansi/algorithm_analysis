#include <bits/stdc++.h>
using namespace std;
int a[110];
int dp[110];
int dp2[110];
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
        memset(dp, 127, sizeof(dp));
        for (int  i = 0; i < n; i++)
        {
            if (a[i] <= dp[p])
                dp[++p] = a[i];
            else
                *upper_bound(dp+1, dp+p+1, a[i], greater<int>()) = a[i];

        }
        int q = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > dp2[q])
                dp2[++q] = a[i];
            else
                *lower_bound(dp2+1, dp2+q+1, a[i]) = a[i];
        }

        cout << p << " " << q << endl;
    }

}