#include <iostream>
using namespace std;
int a[1000];
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        //for(int j=n; j>0; j--)
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                int h = a[i];
                a[i] = a[i - 1];
                a[i - 1] = h;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << ' ';
        }
        cout << a[n - 1]<<endl;
    }
}