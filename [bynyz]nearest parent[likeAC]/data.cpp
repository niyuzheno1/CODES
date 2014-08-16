#include "mode.h"
#include "iodata.h"
using namespace std;
#define MN 50100
#define MK 1010
int f[MN+10],tot,st[MN+10],a[MN+10],b,fa[MN+10];
pii c[MN+10];
int gf(int x){
 if(x == f[x])
  return x;
 return (f[x]=gf(f[x]));
}
struct _edge{
 int n,f,v;
};
_edge lk[MN*2];
void ad(int x,int y){
 lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;
 ++tot;
}
void add(int x,int y){
 ad(x,y);
 ad(y,x);
}
int lastans;
void uni(int x,int y){
 f[gf(x)] = f[gf(y)];
}
void dfs(int x){
 TRA(i,x)
 {
  lk[i^1].f = 1;
  fa[lk[i].v] = x;
  dfs(lk[i].v);
 }
}
void mkp(int x){
 b= 0;
 while(x != 0){
  ++b;
  c[b] = MP(x,a[x]);
  x = fa[x];
 }
}
int main(int argc, char *argv[])
{
    init("sample.in");CLEAR(st,0xff);
    FILE * std = fopen("sample.out","w");
    int n = MN,m = rand()%MK+1,k = rand()%MN+1;
    pin_(n),pin_(m),pin_(k);nl();
    for(int i = 1;i<=n;++i) a[i] = rand()%m+1,pin_(a[i]), f[i] = i; nl();
    
    for(int i = 1;i<=n-1;++i){
     int times = 0;
     while(true){
     ++times;
     int x = rand()%n+1,y = rand()%n+1;
     if(times > 1000){
      break;
     }
     if(gf(x) != gf(y)){
     pin_(x);pin_(y); nl();uni(x,y);add(x,y);break;
     }
     else
      continue;
     }
     if(times > 1000){
     for(int i = 1;i<=n;++i)
      if(gf(i) != f[gf(1)])
      {
       pin_(1);pin_(i);nl();uni(1,i);add(1,i);
      }
      break;
     }
    }
    dfs(1);
    for(int i = 1;i<=k;++i){
     int x = rand()%n+1;
     pin_(x^lastans);
     mkp(x);
     int ou =rand()%b+1;
     pin_(c[ou].Y^lastans);
     nl();
     for(int i = 1;i<=b;++i)
      if(c[i].Y == c[ou].Y){
       lastans = c[i].X;
       break;
      }
     ff(std,"%d\n",lastans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
