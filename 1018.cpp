#include <iostream>
#include <cstring>
using namespace std;
int s[510], v[510];
int dp[110][510];
int main() {
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n; cin >> n;
        int c; cin >> c;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i] >> v[i];
        }
        memset(dp, 0xF7F7F7F7, sizeof(int) * 510 * c); // use 0xf7 is enough, it will cut the last byte of the int
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        
        for (int i = 1; i <= c ; i++)
        {
            for (int j = 1; j <= n ; j++)
            {
                if (i >= s[j]) dp[i][j] = max(dp[i][j-1], dp[i-s[j]][j-1] + v[j]);
                else dp[i][j] = dp[i][j-1];
            }            
        }
        if (dp[c][n] > 0) cout << dp[c][n] << endl;
        else cout<< 0 <<endl;
        
    }
    
    return 0;
}