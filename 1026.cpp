#include <iostream>
#include <cstring>
using namespace std;
#define maxN 30
#define maxK 30
long long dp[maxN][maxK];
int sum[maxN][maxN];
int a[maxN];
int main() {
    int m; cin >> m;
    while (m--)
    {
        int n; cin >> n;
        int k; cin >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(dp, 0, sizeof(long long) * maxN * maxK);
        for (int i = 1; i <=n; i++)
        {
            sum[i][i] = a[i];
        }
        
        for (int len = 1; len < n; len++)
        {
            for (int i = 1; i+len <= n; i++)
            {
                int j = i+len;
                sum[i][j] = sum[i][j-1] + a[j];
            }            
        }
        
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = sum[1][i];
        }
        
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[k][j-1] * sum[k+1][i]);
                }                
            }            
        }
        // 虽然没有得到所有的状态情况，但求解出来的状态结果必然比没有加入的结果大    
        cout << dp[n][k] << endl;        
    }
    
    return 0;
}