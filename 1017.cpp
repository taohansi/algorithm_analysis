#include <iostream>
using namespace std;
int n;
int a[50010];
int temp[50010];
int inverse(int lo, int hi) {
    if(lo == hi) return 0;
    int mi = (lo + hi)/2;
    int le = inverse(lo, mi);
    int ri = inverse(mi+1, hi);
    int i = lo;
    int j = mi+1;
    int count = 0;
    for (int k = lo; k <= hi; k++)
    {
        if (i==mi+1) temp[k] = a[j++];
        else if(j==hi+1) temp[k] = a[i++];
        else if(a[i]<=a[j]) temp[k] = a[i++];
        else { count += mi-i+1; temp[k] = a[j++]; }
    }
    for (int k = lo; k <= hi; k++)
        a[k] = temp[k];
    return le + ri + count;
}
int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << inverse(0, n-1) << endl;
    }
    
    return 0;
}