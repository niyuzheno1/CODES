#include "mode.h"

using namespace std;
const int MN = 1000100;
int a[MN];
int main(int argc, char *argv[])
{
    freopen("output.txt","w",stdout);
    freopen("debug.txt","r",stdin);
    for(int i = 0;i<MN;++i)
     scanf("%d",&a[i]);
    freopen("p1.txt","r",stdin);
    for(int i = 0;i<MN;++i)
    {
     int x = 0;scanf("%d",&x);
     if(x != a[i])
      printf("%d ",i);
    }
    puts("");
    closeIO();
    return EXIT_SUCCESS;
}
