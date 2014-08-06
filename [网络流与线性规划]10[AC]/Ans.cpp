#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
#define MN 1010*2
#define MM 1010*1010*4
int tttt[5];
struct _edge{int n,v,f,c,ppu;};
_edge lk[MM];
int st[MN],pre[MN],d[MN];
int n,p,m,f,o,S;
#define tot tttt[0]
void init(){
 tot = 1;
}
void ad(int x,int y,int z,int w){
 ++tot;
 lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;lk[tot].c = w;lk[tot].f = z;
}
#undef tot
#define LEF(x) x+1
#define RIG(x) x+n+1
void add(int x,int y,int z,int w){
 if(y == 39)
  y = 39;
 ad(x,y,z,w);ad(y,x,0,-w);
}
bool spfa(int s,int t){
 CLEAR(d,0x7f);CLEAR(pre,0);
 d[s] = 0;
 queue<int> q;
 q.push(s);
 while(!q.empty())
 {
  int x = q.front();q.pop();
  TRA(i,x)
   if(lk[i].f > 0 && d[x]+lk[i].c<d[lk[i].v]){
    d[lk[i].v] = d[x]+lk[i].c;
    pre[lk[i].v] = i;
    q.push(lk[i].v);
   }
 }
 return d[t] < INF;
}
int ref(int & ans,int s,int t){
 int mf = INF,cost = 0;
 for(int i = pre[t];i;i=pre[lk[i^1].v]){
  mf = min(mf,lk[i].f);
  cost += lk[i].c;
 }
 ans += mf * cost;
 for(int i = pre[t];i;i=pre[lk[i^1].v])
  lk[i].f -= mf,lk[i^1].f += mf;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    CLEAR(st,0xff);
    init();
    scanf("%d%d%d%d%d%d",&n,&p,&m,&f,&o,&S);
    int s = 1,t = RIG(n+1);
    for(int i = 1;i<=n;++i){
     int x;scanf("%d",&x);
     add(s,LEF(i),x,0);add(RIG(i),t,x,0);
     add(s,RIG(i),INF,p);
     if(i+1 <=n)
     add(LEF(i),LEF(i+1),INF,0);
     if(i+m<=n)
     add(LEF(i),RIG(i+m),INF,f);
     if(i+o<=n)
     add(LEF(i),RIG(i+o),INF,S);
    }
    int ans= 0;
    while(spfa(s,t))
     ref(ans,s,t);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
