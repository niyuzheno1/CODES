#include "mode.h"

using namespace std;
const int MN = 1010,MM = 1010;
int a[MN][MM];
int main(int argc, char *argv[])
{
    setIO("AOMap");
    int n=gi,m=gi,q=gi;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      a[i][j] = gi;
    for(int k = 1;k<=q;k++)
    {
     int u=gi,v=gi,x=gi,y=gi,ans = 0;
     for(int i = u;i<=x;i++)
      for(int j = v;j<=y;j++)
       ans += a[i][j];
     printf("%d\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
