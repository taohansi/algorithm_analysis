#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxN 10010
int a[maxN];
int dp[maxN];
int main() {
    int m; cin >> m;
    while (m--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int p = 0;
        memset(dp, 0x80, sizeof(int) * maxN); // 注意初始化
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= dp[p])
                dp[++p] = a[i];
            else
            {
                *upper_bound(dp+1, dp+p+1, a[i]) = a[i]; // dp+n+1 -> dp+p+1
                // 不上升或者不下降子序列采用upper_bound
            }            
        }
        cout << p << endl;
    }
    
    return 0;
}