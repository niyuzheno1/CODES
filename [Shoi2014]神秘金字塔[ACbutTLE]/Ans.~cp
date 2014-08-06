#include "mode.h"
#define ML 11
#define MA 12

typedef map<pii,int> miii;
typedef miii::iterator mitr;
int n,m,h,ans,a[11],b[21],mod=15;
miii f[ML][ML];

void nex(int & sx,int & sy,int x,int y)
{
     ++y;if(y > m) ++x,y = 1;
     sx = x,sy = y;
}

void tra(int n,int x,int y,int z,int lastans )
{
     if(n< 0) return;
     int nx,ny;nex(nx,ny,x,y);
     if(y == 1)
     {
      int p = h;
      for(;a[p]<x && p != 0;--p);
      z>>=4;z<<=4;
      z = z|p;//<=> f[x][y] = p;
      if(n-p >= 0)
      f[nx][ny][MP(n-p,z)] += lastans;
     }
     else
     {
     int up = (z>>(4*(y-1)))&mod;
     int le = (z>>(4*(y-2)))&mod;
     int v = min(up,le);
     int u = max(x,y);
     for(int i = 0;i<=v;++i)
      if(a[i] >= u){
      int ux = mod<<(4*(y-1));
      z = z|ux;
      z = z^ux;
      z = z|(i<<(4*(y-1)));
      f[nx][ny][MP(n-i,z)] += lastans;
      }
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, h = gi;n/=4;
    for(int  i = 1;i<=h;++i) a[i] = gi,a[i]/=2,m=max(m,a[i]);
    a[0] = m+1;
    for(int  i = 1;i<=h;++i)
     for(int j = 1;j<=a[i];++j)
      b[j] = i;
    int st = 0;
    for(int i = m;i>=1;--i)
     st<<=4,st|=b[i],n-=b[i];
    f[2][1][MP(n,st)] = 1;
    for(int i = 2;i<=m;++i)
     for(int j = 1;j<=m;++j)
      for(mitr it = f[i][j].begin();it != f[i][j].end();++it)
       tra((*it).X.X,i,j,(*it).X.Y,(*it).Y);
    int ans = 0;
    for(mitr it = f[m][m].begin();it != f[m][m].end();++it)
     if((*it).X.X == 0)
     ans += (*it).Y;
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
