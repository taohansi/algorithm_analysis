#include <iostream>
#include <cstring>
using namespace std;
int a[510];
int v[510];
int dp[110][510];
int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        int c;
        cin >> c;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> v[i];
        }
        memset(dp, 0, sizeof(int) * 510 * c);
        for (int i = 1; i <= c; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i - a[j] >= 0) dp[i][j] = max(dp[i][j-1], dp[i - a[j]][j-1] + v[j]);
                else dp[i][j] = dp[i][j-1];
            }
            
        }
        cout << dp[c][n] << endl;
        
    }
    
    return 0;
}