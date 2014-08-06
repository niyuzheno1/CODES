#include "mode.h"
#define MN 43
const int dx[] = {0,-1,-1,-1,-2};
const int dy[] = {0,1 ,0,-1,0};
int64 ans[MN],m,n;
int64 f[MN][MN],g[MN][MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;
    for(int i = 1;i<=m;++i) g[1][i] = int64(1)<<int64(i);
    for(int i = 2;i<=n+1;++i)
     for(int j = 1;j<=m;++j)
      for(int k = 1;k<=4;++k)
       g[i][j] ^= g[i+dx[k]][j+dy[k]];
    for(int i = 1;i<=m;++i)
     for(int j = 1;j<=m;++j)
      f[i][j] = ((g[n+1][i]>>j)&1);
    for(int i = 1;i<=m;++i)
    {
     int tmp = i;
     while(!f[tmp][i]) ++tmp;
     if(tmp > m) continue;
     for(int j = i;j<=m;++j) swap(f[tmp][j],f[i][j]);
     for(int j = i+1;j<=m;++j)
     {
      int u = f[j][i];
      if(!u) continue;
      for(int k = i;k<=m;++k)
       f[j][k] ^= f[i][k];
     }
    }
    //up process 
    for(int i = m;i>=1;--i)
    {
     if(!f[i][i]) ans[i] = 1;
     for(int j = i-1;j>=1;--j)
     if(f[j][i])
     {
      f[j][i] ^= 1;
      ans[j] ^= ans[i];
     }
    }
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;printf("%c",j==m?'\n':' '),++j)
     {
     int64 u = g[i][j],v = 0;//ff(debug,I64D,u);ff(debug,"\n");
      for(int k = 1;k<=m;++k)
       if(((u>>k)&1)) v ^= ans[k];
      printf(I64D,v);
     }
    closeIO();
    return EXIT_SUCCESS;
}
