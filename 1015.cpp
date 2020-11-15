#include <iostream>
#include <algorithm>
using namespace std;
struct buliding
{
    int a, b, h;
} bu[50010];
struct skyline
{
    int x, h;
} sk[100020], temp[100020];
int N;

int zip() {
    int len = 2 * N;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == 0 || sk[i-1].h != sk[i].h)
            sk[j++] = sk[i];
    }
    return j;
}
void get_skyline(int lo, int hi)
{
    if (lo == hi)
    {
        sk[2 * lo].x = bu[lo].a, sk[2 * lo].h = bu[lo].h;
        sk[2 * lo + 1].x = bu[lo].b, sk[2 * lo + 1].h = 0;
        return;
    }
    int mi = (lo + hi) / 2;
    get_skyline(lo, mi);
    get_skyline(mi + 1, hi);
    int i = 2 * lo;
    int j = 2 * (mi + 1);
    int lh = 0;
    int rh = 0;
    for (int k = 2 * lo; k <= 2 * hi + 1; k++)
    {
        if (i == 2 * mi + 2) { // no need to update height anymore
            temp[k] = sk[j++];
            
        }
        else if (j == 2 * hi + 2) {
            temp[k] = sk[i++];
        }
        else if (sk[i].x < sk[j].x) {
            lh = sk[i].h;
            temp[k].x = sk[i++].x;
            temp[k].h = max(lh, rh);
            
        }
        else if (sk[j].x < sk[i].x){
            rh = sk[j].h;
            temp[k].x = sk[j++].x;
            temp[k].h = max(lh, rh);
            
        }else{
            lh = sk[i].h;
            rh = sk[j].h;
            temp[k].x = sk[i++].x;
            temp[k].h = max(lh, rh);
        }      
    }

    for (int k = 2 * lo; k <= 2 * hi + 1; k++)
        sk[k] = temp[k];
    
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> bu[i].a >> bu[i].b >> bu[i].h;
    }
    get_skyline(0, N - 1);
    int len = zip();
    for (int i = 0; i < len; i++)
    {
        cout<<sk[i].x<<" "<<sk[i].h<<endl;
    }
    
    return 0;
}