#include "mode.h"
#undef TRA
#undef INF
#define INF 0x7f7f7f7f
#define TRA(x,y) for(int x = st[y];x;x = lk[x].n)
#define FIND(x,y) for(int x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x =pre[y];x;x = pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]])== 0) break;
#define BAL(x) lk[x].c-lk[x].f
#define MN 3000*4
#define MM 6000*2
struct edge{
 int v,f,c,n;
};
edge lk[MM];
int st[MN],num[MN],d[MN],q[MN],pre[MN],cur[MN],node,ans,e=1;
void add(int x,int y,int z)
{
     ++e,lk[e].n = st[x],st[x] = e,lk[e].v = y,lk[e].c = z;
}
void bfs(int t){
     CLEAR(d,0x7f);
     d[t] = 0;
     int r = 0;q[r = 1] = t;
     ++num[d[t]];
     for(int i = 1;i<=r;){
      int u = q[i];++i;
      TRA(x,u)
       if(d[lk[x].v]>=INF){
       d[lk[x].v] = d[u]+1;
       ++num[d[lk[x].v]];
       q[++r] = lk[x].v;
       }
     }
}
int aug(int t)
{
    int ret =t,mf = INF;
    PRE(x,t)
     if(BAL(x) <= mf)
     {
      mf = BAL(x);
      ret = lk[x^1].v;
     }
    ans += mf;
    PRE(x,t)
     lk[x].f+=mf,lk[x^1].f -= mf;
    return ret;
}
void isap(int s,int t){
     bfs(t);
     int u = s;
     for(int i = 1;i<=node;++i) cur[i] = st[i];
     while(d[s] < node){
      if(u == t) 
       u = aug(t);
      int adv = 0;
      FIND(x,u)
       if(BAL(x)>0 && d[lk[x].v]+1 == d[u])
       {
        cur[u] = x;u = lk[x].v;pre[u] = x; 
        adv = 1;
        break;
       }
      if(!adv){
       GAP(u);
       int md = node;
       TRA(x,u)
        if(BAL(x)>0)
         md = min(md,d[lk[x].v]);
       d[u] = md+1;cur[u]=st[u];++num[d[u]];
       if(u != s) u = lk[pre[u]^1].v;
      }
     }
}
int n,m;
#define LFT(_t) _t+1
#define RIG(_t) _t+n+1
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    int s = 1,t = RIG(n)+1;node = RIG(n)+1;
    for(int i = 1;i<=n;++i)
     add(s,LFT(i),1),add(LFT(i),s,0);
    for(int i = 1;i<=n;++i)
     add(RIG(i),t,1),add(t,RIG(i),0);
    for(int i = 1;i<=m;++i){
     int x = gi,y = gi;
     add(LFT(x),RIG(y),INF);
     add(RIG(y),LFT(x),0);
    }
    isap(s,t);
    printf("%d",n-ans);
    closeIO();
    return EXIT_SUCCESS;
}
