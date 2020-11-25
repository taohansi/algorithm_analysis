#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[510];
double p[510];
double q[510];
double dp[510][510];
double w[510][510];
int main () {
    int m; cin >> m;
    while (m--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 0; i <= n; i++)
            cin >> q[i];
        for (int i = 1; i <= n; i++)
        {
            w[i][i-1] = q[i-1];
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                w[i][j] = w[i][j-1] + p[j] + q[j];
                // printf("w %d %d %.4f\n", i, j, w[i][j]);
            }
            
        }
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = 1e256;
                // if (i == j+1)
                //     dp[i][j] = 0;
            }
            
        }
        
        for (int len = 0; len <= n-1; len++)
        {
            for (int i = 1; i + len<=n; i++)
            {
                int j = i + len;
                for (int k = i; k <= j; k++)
                {
                    double left = k > i ? dp[i][k-1] : 0.0;
                    double right = k < j ? dp[k+1][j] : 0.0; // 注意越界，不能光用dp中初始化位0进行处理
                    if (left + right + w[i][j] < dp[i][j])
                        dp[i][j] = left + right + w[i][j];
                }
                // printf("dp %d %d %.4f\n", i, j, dp[i][j]);
                
            }
        }
        printf("%.6f\n", dp[1][n]);
        
        
    }
    
    return 0;
}