#include <bits/stdc++.h>
using namespace std;
struct Pos
{
    int x, y;
} s,p[110];
int len = 0;
int stk[110];
bool cmp(Pos& a, Pos& b)
{
    if (a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}
bool cmp_ang(Pos& a, Pos& b)
{
    if (a.x == s.x && a.y == s.y) return true;
    else if (b.x == s.x && b.y == s.y) return false;
    else if (a.x-s.x == 0 && b.x-s.x == 0) return a.y > b.y;
    else return (double(a.y) - s.y) * (b.x - s.x) < (double(b.y) - s.y) * (a.x-s.x);
}
bool on_right(Pos& a, Pos& b, Pos& c)
{
    int u1 = b.x - a.x;
    int v1 = b.y - a.y;
    int u2 = c.x - a.x;
    int v2 = c.y - a.y;
    return v1 * u2 - u1 * v2 >= 0;
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
        s.x = 0;
        s.y = 0x7fffffff;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x;
            cin >> p[i].y;
        }
        sort(p, p+n, cmp);
        s = p[0];
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

        stk[0] = 0;
        stk[1] = 1;
        int top = 1;
        for (int i = 2; i<=len; i++)
        {
            while (top >= 1 && on_right(p[stk[top-1]], p[stk[top]], p[i]))
            {
                --top;
            }
            stk[++top] = i;

        }
        cout<<"case "<<i+1<<":"<<endl;
        for (int i = 0; i<=top; i++)
        {
            cout<<p[stk[i]].x<<" "<<p[stk[i]].y<<endl;
        }

    }

}