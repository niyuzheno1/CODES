#include "mode.h"

#define MN 110
#define MV 100010
int n,m,V,c[MN],v[MN],lastans;
int f[MV];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m= gi,V = gi;
    for(int i = 1;i<=n;++i) v[i] = gi,c[i] = gi;
    for(int i = 1;i<=m;++i)
    {
     CLEAR(f,0);
     int k = gi;k^=lastans;
     for(int j = 1;j<=n;++j)
      if(j != k)
      for(int l = v[j];l<=V;++l)
       f[l] = max(f[l],f[l-v[j]]+c[j]);
     printf("%d\n",lastans = f[V]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
