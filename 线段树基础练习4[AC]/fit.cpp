#include "mode.h"

int main(int argc, char *argv[])
{
    freopen("tsinsenD5530.in","r",stdin);
    freopen("tsinsenD5530.in1","w",stdout);
    int n,m;
    n = gi,m = gi;
    printf("%d %d\n",n,m);
    for(int i = 1,x,y;i<=n;++i)
    {
      x= gi,y = gi;
      printf("%d %d\n",x,y);
    }
    int times = 0;
    for(int i = 1;i<=m;++i)
    {
     int opt = gi,x=gi,y=gi;
     printf("%d %d %d\n",opt,x,y);
     if(opt == 3)
      ++times;
     if(times == 26){
      printf("%d",i);
      break;
      }
    }
    return EXIT_SUCCESS;
}
