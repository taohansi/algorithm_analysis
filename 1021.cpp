#include <iostream>
#include <cstring>
using namespace std;
int l[10010];
int p[10010];
int dp[10010];
int main() {
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int c; cin >> c;
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> p[i];
        }
        memset(dp, 0, sizeof(int) * c + 10);
        for (int i = 1; i <= n; i++)
            dp[l[i]] = p[i];
        for (int i = 0; i <= c; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i >= l[j]) dp[i] = max(dp[i], dp[i-l[j]] + p[j]);
            }  
        }
        cout << dp[c] << endl;
    }
    
    return 0;
}