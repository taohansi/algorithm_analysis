#include <iostream>
using namespace std;
int m;
int a[50010];
int b[50010];
int n;
int reverse_num(int lo, int hi)
{
    if (hi == lo)
        return 0;

    int mi = (lo + hi) / 2;
    int x = reverse_num(lo, mi);
    int y = reverse_num(mi + 1, hi);
    int i = lo;
    int j = mi + 1;
    int count  = 0;
    for (int k = lo; k <= hi; k++) {
        if (i == mi + 1) { b[k] = a[j]; j++; }
        else if (j == hi + 1) { b[k] = a[i]; i++; }
        else if (a[i] <= a[j]) { b[k] = a[i]; i++; }
        else if (a[j] < a[i]) { count += mi-i+1; b[k] = a[j]; j++; }
    }
    for (int i = lo; i <= hi; i++)
        a[i] = b[i];
    
    return x + y + count;
}
int main()
{
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << reverse_num(0, n - 1) << endl;
    }
}