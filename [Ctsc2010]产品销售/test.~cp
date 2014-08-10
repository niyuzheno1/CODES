#include "mode.h"
#define MN 100010
int n,tot;
int d[MN],p[MN],u[MN],m[MN],c[MN],s,t,st[MN],dis[MN],pre[MN],q[MN];
#define vex(x) (x+1)
struct li{int n,v,c,f,u;};
li lk[MN*3];
void ad(int x,int y,int c,int u){
 ++tot;
 lk[tot].v = y;lk[tot].c = c;lk[tot].u = u;lk[tot].n = st[x];st[x] = tot;
}
void add(int x,int y,int c,int u){
 ad(x,y,c,u);ad(y,x,0,-u);
}
bool aug()
{
 CLEAR(dis,0x7f);
 dis[s] = 0;
 int r ;
 q[r = 1] = s;
 for(int i = 1;i<=r;++i){
  int x = q[i];
  TRA(j,x)
   if(lk[j].c > 0 && dis[lk[j].v] > dis[x] + lk[j].u){
    dis[lk[j].v] = dis[x] + lk[j].u;
    pre[lk[j].v] = j;
    ++r;q[r] = lk[j].v;
   }
 }
 return dis[t] < INF;
}
int sum(){
 int mcost = 0,mf = INF;
 for(int i = t;i!=s;i=lk[pre[i]^1].v) 
  mcost += lk[pre[i]].u,mf = min(lk[pre[i]].c,mf);
 for(int i = t;i;i=lk[pre[i]^1].v)
  lk[pre[i]].c -= mf,lk[pre[i]^1].c += mf;
 return mcost * mf;
}
int main(int argc, char *argv[])
{
    tot = 1;CLEAR(st,0xff);
    setIO();
    n = gi;s = 1,t = n+2;
    for(int i = 1;i<=n;++i) d[i] = gi;
    for(int i = 1;i<=n;++i) u[i] = gi;
    for(int i = 1;i<=n;++i) p[i] = gi;
    for(int i = 1;i<=n-1;++i) m[i] = gi;
    for(int i = 1;i<=n-1;++i) c[i] = gi;
    for(int i = 1;i<=n;++i) add(s,vex(i),u[i],p[i]);
    for(int i = 1;i<=n-1;++i){
     add(vex(i),vex(i+1),INF,m[i]);
     add(vex(i+1),vex(i),INF,c[i]);
    }
    for(int i = 1;i<=n;++i) add(vex(i),t,d[i],0);
    int cost = 0;
    while(aug())
     cost += sum();
    printf("%d\n",cost);
    closeIO();
    return EXIT_SUCCESS;
}
