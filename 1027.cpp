#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxN 10010
struct Act
{
    int s, f, v;
}act[maxN];
int dp[maxN];
int p[maxN];
bool cmp(Act &a, Act &b)
{
    return a.f < b.f;
}
int main() {
    int m; cin >> m;
    while (m--)
    {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> act[i].s >> act[i].f >> act[i].v;
        }
        sort(act+1, act+n+1, cmp); // sort范围
        memset(dp, 0, sizeof(int) * maxN);

        // 二分!!!
        for (int i = 1; i <= n; i++)
        {
            int lo = 1, hi = n+1;
            int k = act[i].s;
            while (lo < hi)
            {
                int mid = lo + (hi-lo)/2;
                if(act[mid].f <= k) lo = mid+1;
                else hi = mid;
            }
            p[i] = lo - 1;
        }
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i-1], dp[p[i]] + act[i].v);
        }
        cout << dp[n] << endl;
        
        
    }
    
    return 0;
}