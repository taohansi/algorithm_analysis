#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    int x;
    int y;
} p[50010], pt[50010];

bool cmp(Pos& a, Pos& b) 
{ 
    // if(a.x < b.x) return true;
    if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
bool cmp_y(Pos& a, Pos& b) { return a.y < b.y; }
double dist(Pos& a, Pos& b) { return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2)); }
double find_nearst(int l, int h)
{
    if (h-l == 0) return ((long long int) 2) << 40;
    if (h-l == 1)  return dist(p[l], p[h]);
    int mid = (l+h)/2;
    int mid_x = p[mid].x;
    double d1 = find_nearst(l, mid);
    double d2 = find_nearst(mid+1, h);
    double d = min(d1, d2);
    int k = 0;
    for (int i = l ; i <= h; i++)
    {
       if (abs(p[i].x - mid_x) < d)
       {
           pt[k].x = p[i].x;
           pt[k].y = p[i].y;
           k++;
       }
       
    }
    sort(pt, pt+k, cmp_y);
    for (int i = 0; i < k; i++)
    {
        int count = 0;
        for (int j = i+1; j < k && abs(pt[i].x - pt[j].x) < d && count <= 6; j++, count++)
        {
            double t = dist(pt[i], pt[j]);
            d = min(t, d);
        }
        
    }
    return d;
}

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        sort(p, p+n, cmp);
        printf("%.2f\n", find_nearst(0, n-1));
    }
}