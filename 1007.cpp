#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
int a[40];
long long dp[40][6];
long long num(int i, int j)
{
    long long num = 0;
    long long temp = 1;
    
    for (int k = j; k >= i; k--)
    {
        num += a[k] * temp;
        temp *= 10;
    }
    return num;
    
}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {   
        memset(dp, 0, sizeof(dp));
        cin>>n>>k;
        int c;
        int j = 0;
        getchar();
        while ((c=getchar()) != EOF && j < n)
        {
            a[j] = c - '0';
            j++;
        }

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            dp[i][0] = sum; 
            sum *= 10;
        }
        
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {   
                for (int m = 0; m < i; m++)
                {
                    dp[i][j] = max(dp[m][j-1] * num(m+1, i), dp[i][j]);
                    // cout<<"dp "<<i<<" "<<j<<" "<<m<<" "<<dp[m][j-1]<<" "<<num(m+1, i)<<" "<<dp[i][j]<<endl;
                }
                
            }
            
        }
        cout<<dp[n-1][k]<<endl;    
    }
    
}