#include <iostream>
#include <map>
using namespace std;
int n;
int a[50010];
map<int, int> mp;
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        int x;
        cin >> x;
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp.find(x - a[i]) == mp.end())
                mp[a[i]] = i;
            else
                f = true; // can't break because you have elements still need read
        }
        mp.clear();
        if (f)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}