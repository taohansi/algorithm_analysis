#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        int min1, min2;
        cin >> min1>>min2;
        if(min1 > min2){
            int h = min1;
            min1 = min2;
            min2 = h;
        }
        for (int j = 0; j < n - 2; j++)
        {
            int x;
            cin >> x;
            if (x < min1)
            {
                min2 = min1;
                min1 = x;
            }else if(min1 < x && x < min2)
            {
                min2 = x;
            }
        }
        cout<<min2<<endl;
    }
}