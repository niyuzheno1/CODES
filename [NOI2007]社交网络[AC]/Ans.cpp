#include "mode.h"
typedef double ld;
const int MN =  110;
int f[MN][MN];
int g[MN][MN];
double ans[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi, m =gi;
    CLEAR(f,0x10);
    for(int i = 1;i<=n;++i)
     f[i][i] = 0,g[i][i] = 1;
    for(int i = 1,a,b,c;i<=m;++i)
    {
     a= gi;b = gi;c = gi;
     f[a][b] = f[b][a] = c; 
     g[a][b] = g[b][a] = 1;
    }
    for(int k = 1;k<=n;++k)
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=n;++j)
       if(i != j && j != k && i != k){
       if(f[i][k]+ f[k][j] == f[i][j])
        g[i][j] += g[i][k]*g[k][j];
       if(f[i][k]+ f[k][j] <  f[i][j])
        f[i][j] = f[i][k]+ f[k][j],g[i][j] = g[i][k]*g[k][j];
      }
    
    for(int k = 1;k<=n;++k)
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=n;++j)
      if(i != j && j != k && i != k){
       if(f[i][k]+ f[k][j] == f[i][j])
        ans[k] += (ld(g[i][k])*ld(g[k][j]))/ld(g[i][j]);
      }
    for(int k = 1;k<=n;++k)
     printf("%.3f\n",ans[k]);
    closeIO();
    return EXIT_SUCCESS;
}
