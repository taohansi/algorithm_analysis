#include <iostream>
#include <cstring>
using namespace std;
int m;
int n;
int a[50010];
int dp[50010];
int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memset(dp, 0, n * sizeof(int));
        dp[0] = a[0];
        int ans = a[i];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i-1]+a[i], a[i]);
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }
}
