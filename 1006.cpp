#include <iostream>
using namespace std;
int a[1001];
int n;
void pop_up(int k)
{
    while (k > 1 && a[k] < a[k/2])
    {
        swap(a[k], a[k/2]);
        k = k/2;
    }
    
}
void pop_down(int k)
{
    while (true)
    {
        int j = 2*k;
        if(j > n) break;
        if(a[j+1] < a[j] && (j < n)) j++;
        if(a[k] < a[j]) break;
        swap(a[k], a[j]);
        k = j;
    }
    
}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int j = n/2; j >=1; j--)
        {
            pop_down(j);
        }
        
        for (int i = 1; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n]<<endl;
    }
}