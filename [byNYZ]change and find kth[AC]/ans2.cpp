#include "mode.h"

using namespace std;
const int MN = 5001;
int a[MN],n,m,b[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, m= gi;
    for(int i = 1;i<=n;++i) a[i] = gi;
    for(int i = 1,x,y,z;i<=m;++i)
    {
     int opt = gi;
     switch(opt){
      case 1:
           x = gi, y = gi,z = gi;
           for(int i = 1;i<=n;++i)
            b[i] = a[i];
           sort(b+x,b+y+1);
           printf("%d\n",b[x+z-1]);
           break;
      case 2:
           x = gi, y = gi;
           a[x] = y;
           break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
