#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int c;
        while ((c = getchar()) != EOF)
        {
            if (c == '\n')
            {
                cout<<count<<endl;
                break;
            }
            if ('0'<=c && c<= '9')
                count++;
        }
    }
}