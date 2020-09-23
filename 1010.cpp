#include <iostream>
using namespace std;
int a[20010];
void bin_search(int l, int h, int x , int fa)
{
    if (l > h)
    {
        printf("not found, father is %d\n", a[fa]);
        return;
    }
    int mid = (l+h)/2;
    if(a[mid] < x) bin_search(mid+1, h, x, mid);
    else if(a[mid] > x) bin_search(l, mid-1, x, mid);
    else printf("success, father is %d\n", a[fa]);

}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bin_search(0, n-1, x, 0);
    }


}