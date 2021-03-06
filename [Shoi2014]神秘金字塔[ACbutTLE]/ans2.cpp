#include "mode.h"
int n,m,h,ans;
int a[11];
int f[21][21];
void nex(int & sx,int & sy,int x,int y)
{
     ++y;if(y > m) ++x,y = 1;
     sx = x,sy = y;
}

void dfs(int x,int y,int z)
{
     if(z < 0)
      return;
     if(x > m && z == 0)
     {
      /*for(int i = 1;i<=m;++i,ff(debug,"\n"))
       for(int j = 1;j<=m;++j)
        ff(debug,"%d ",f[i][j]);
      ff(debug,"\n");*/
      ++ans;
      return;
     }
     if(x > m)
       return;
     int nx,ny;
     nex(nx,ny,x,y);
     if(y == 1)
     {
      int p = h;
       for(;a[p]<x && p != 0;--p);
      f[x][y] = p;
      dfs(nx,ny,z-p);
      f[x][y] = 0;
     }
     else
     {
      int v = min(f[x-1][y],f[x][y-1]);
      int u = max(x,y);
      for(int i = 0;i<=v;++i)
       if(a[i]>=u){
       f[x][y] = i;
       dfs(nx,ny,z-i);
       f[x][y] = 0;
      }
     }
}
int main()
{
    setIO("sample");
    n = gi, h = gi;n/=4;
    for(int  i = 1;i<=h;++i) a[i] = gi,a[i]/=2,m=max(m,a[i]);
    for(int  i = 1;i<=h;++i)
     for(int j = 1;j<=a[i];++j)
      f[1][j] = i;
    for(int i = 1;i<=m;++i)
     f[i][0] = 11,n-=f[1][i];
    a[0] = m+1;
    dfs(2,1,n);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
