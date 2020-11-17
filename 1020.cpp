#include <iostream>
#include <cstring>
using namespace std;
int r[510];
int c[510];
int dp[510][510];
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> r[i] >> c[i];
        memset(dp, 0x7f, sizeof(int) * 510 * 510);
        for (int i = 1; i <= n; i++)
            dp[i][i] = 0;
        for (int len = 1; len <= n; len++)
        {
            for (int i = 1; i + len<= n; i++)
            {
                int j = i + len;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
                }
            }
        }
        cout << dp[1][n] << endl;
    }

    return 0;
}