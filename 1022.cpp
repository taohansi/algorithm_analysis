#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char s1[510];
char s2[510];
int dp[510][510];
int main () {
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s2;
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        memset(dp, 0, sizeof(int) * 510 * 510);
        for (int i = 1; i <= len1 ; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (s1[i-1] == s2[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
            
        }
        cout << dp[len1][len2] <<endl;        
    }
    
}