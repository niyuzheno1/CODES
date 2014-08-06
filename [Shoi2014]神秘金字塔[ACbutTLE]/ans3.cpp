/*#include "mode.h"

#define ML 15
#define MA 12

typedef map<pii,int> miii;
typedef miii::iterator mitr;
int n,m,h,ans,a[11],b[21],mod=15,modd=1000000007;
miii f[ML][ML];
void addmod(int &x,int y,int z)
{
     x = y+z;
     while(x > modd) x-=modd;
     while(x < 0) x+=modd;
}

void nex(int & sx,int & sy,int x,int y)
{
     ++y;if(y > m) ++x,y = 1;
     sx = x,sy = y;
}

void tra(int n,int x,int y,int z,int lastans )
{
     if(n< 0) return;
     int nx,ny;nex(nx,ny,x,y);
	 /*if(x == 4 && y == 1 && (z !=13107||(z==13107 && n != 9)))
		  return;
	 if(x == 4 && y == 2)
		  x = 4;
	 if(x == 4 && y == 3 && z ==13107 )
		  x = 4;
	 if(y==1&&z == 13107)
		 z = 13107;*//*
     if(y == 1)
     {
      int p = h;
      for(;a[p]<x && p != 0;--p);
      z = z|mod,z = z^mod;
      z = z|p;//<=> f[x][y] = p;
      if(n-p >= 0)
      addmod(f[nx][ny][MP(n-p,z)],f[nx][ny][MP(n-p,z)],lastans);
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
      if(n-i >= 0)
      addmod(f[nx][ny][MP(n-i,z)],f[nx][ny][MP(n-i,z)],lastans);
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
    for(mitr it = f[m+1][1].begin();it != f[m+1][1].end();++it)
     if((*it).X.X == 0)
     addmod(ans,ans,(*it).Y);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}*/
#include "mode.h"

#define ML 15
#define MA 12
typedef int64 LL;
typedef pair<LL,LL> pLL ;
typedef map<pLL,LL> miii;
typedef miii::iterator mitr;
LL n,m,h,ans,a[11],b[21],mod=15,modd=1000000007;
miii f[ML][ML];
void addmod(LL &x,LL y,LL z)
{
     x = y+z;
     while(x > modd) x-=modd;
     while(x < 0) x+=modd;
}

void nex(LL & sx,LL & sy,LL x,LL y)
{
     ++y;if(y > m) ++x,y = 1;
     sx = x,sy = y;
}

LL calc(LL x)
{
            LL ret = 0;
            while (x > 0)
            {
                  int y = x&mod;
                  if(y == 0)
                   break;
                  else
                   ret += y;
                  x>>=4;
            }
            return ret;
}

void tra(LL n,LL x,LL y,LL z,LL lastans )
{
     if(n< 0) return;
     LL nx,ny;nex(nx,ny,x,y);
	 /*if(x == 4 && y == 1 && (z !=13107||(z==13107 && n != 9)))
		  return;
	 if(x == 4 && y == 2)
		  x = 4;
	 if(x == 4 && y == 3 && z ==13107 )
		  x = 4;
	 if(y==1&&z == 13107)
		 z = 13107;*/
	 if(x==10 && z == 1)
		 z = 1;
     if(y == 1)
     {
      LL p = h;
      for(;a[p]<x && p != 0;--p);
      z = z|mod,z = z^mod;
      z = z|p;//<=> f[x][y] = p;
      if(n-p >= 0)
      addmod(f[nx][ny][MP(n-p,z)],f[nx][ny][MP(n-p,z)],lastans);
     }
     else
     {
     LL up = (z>>(4*(y-1)))&mod;
     LL le = (z>>(4*(y-2)))&mod;
     LL v = min(up,le);
     LL u = max(x,y);
     for(LL i = 0;i<=v;++i)
      if(a[i] >= u){
      LL ux = mod<<(4*(y-1));
      z = z|ux;
      z = z^ux;
      z = z|(i<<(4*(y-1)));
      if(i == 0 && n-calc(z)*(m-i)>0)
        continue;
      
      if(n-i >= 0)
      addmod(f[nx][ny][MP(n-i,z)],f[nx][ny][MP(n-i,z)],lastans);
      }
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, h = gi;n/=4;
    for(LL  i = 1;i<=h;++i) a[i] = gi,a[i]/=2,m=max(m,a[i]);
    a[0] = m+1;
    for(LL  i = 1;i<=h;++i)
     for(LL j = 1;j<=a[i];++j)
      b[j] = i;
    LL st = 0;
    for(LL i = m;i>=1;--i)
     st<<=4,st|=b[i],n-=b[i];
    f[2][1][MP(n,st)] = 1;
    for(LL i = 2;i<=m;++i)
     for(LL j = 1;j<=m;++j)
      for(mitr it = f[i][j].begin();it != f[i][j].end();++it)
       tra((*it).X.X,i,j,(*it).X.Y,(*it).Y);
    LL ans = 0;
    for(mitr it = f[m+1][1].begin();it != f[m+1][1].end();++it)
     if((*it).X.X == 0)
     addmod(ans,ans,(*it).Y);
    printf(I64D,ans);
    closeIO();
    return EXIT_SUCCESS;
}

