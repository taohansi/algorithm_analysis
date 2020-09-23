#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    int x, y;
} s,p[110];
int len = 0;
int stk[110];
bool cmp_ang(Pos& a, Pos& b)
{
    if (a.x == s.x && a.y == s.y) return true;
    else if (a.x-s.x == 0 && b.x-s.x == 0) return a.y < b.y;
    else return (double(a.y) - s.y) * (b.x - s.x) - (double(b.y) - s.y) * (a.x-s.x);
}
bool on_right(Pos& a, Pos& b, Pos& c)
{
    int u = b.x - a.x;
    int v = b.y - a.y;
    return v * c.x - u * c.y;
}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        len = 0;
        s.x = s.y = 0x7fffffff;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x;
            cin >> p[i].y;
            if (p[i].x < s.x && p[i].y < s.y)
            {
                s.x = p[i].x;
                s.y = p[i].y;
            }
        }
        sort(p, p+n, cmp_ang);
        for (int i = 1; i < n; i++)
        {
            if (p[i].x != p[len].x || p[i].y != p[len].y)
            {
                ++len;
                p[len].x = p[i].x;
                p[len].y = p[i].y;
            }
        }

        for (int i = 0; i <= len; i++)
        {
            cout<<p[i].x<<" "<<p[i].y<<" ";
        }

        stk[0] = 0;
        stk[1] = 1;
        stk[2] = 2;
        int top = 2;
        for (int i = 3; i<=len; i++)
        {
            while ()
            {
                /* code */
            }

        }

    }

}