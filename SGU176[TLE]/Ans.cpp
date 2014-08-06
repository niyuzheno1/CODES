#include "mode.h"
#include "netflow.h"
#undef INF
#define INF 0x7f7f7f7f
#define ME 100010
#define MN 210
typedef _nedge edge;
edge lk[ME];
int st[MN],e = 1,d[MN],num[MN],cur[MN],pre[MN],q[MN],ans,node;
void ad(int x,int y,int z)
{++e;lk[e].v = y;lk[e].f = 0;lk[e].c = z;lk[e].n=st[x];st[x]=e;}
void add(int x,int y,int z)
{ad(x,y,z),ad(y,x,0);}
void bfs(int t)
{
     CLEAR(d,0x7f),CLEAR(num,0);
     int r = 0;q[r=1] = t;d[t] = 0;INC(t);
     for(int i = 1;i<=r;++i)
     {
      int u = q[i];
      TRA(x,u)
       if(d[lk[x].v] >= INF)
       {
       d[lk[x].v] = d[u]+1,q[++r] = lk[x].v,INC(lk[x].v);
       }
     }
}
int aug(int t)
{
    int ret = t,mf = INF;
    PRE(x,t)
     if(BAL(x) <= mf)
      ret = lk[x^1].v,mf = BAL(x);
    ans += mf;
    PRE(x,t)
     lk[x].f += mf,lk[x^1].f -= mf;
    return ret;
}
void isap(int s,int t)
{
     ans = 0;
     bfs(t);for(int i = 1;i<=node;cur[i]=st[i],++i);
     int u = s;
     while(d[s]<node)
     {
      if(u == t)
       u = aug(u);
      int adv = 0;
      FIND(x,u)
       if(BAL(x)>0 && d[lk[x].v]+1==d[u])
       {
        adv = 1,u = lk[x].v,pre[u] = x;
       break;
       }
      if(!adv)
      {
      GAP(u);
      int dm = node;
      TRA(x,u)
       if(BAL(x)>0)
        dm = min(dm,d[lk[x].v]);
      cur[u]=st[u],d[u] = dm+1,INC(u);
      if(u != s) u = lk[pre[u]^1].v;
      }
     }
}
struct _info{int x,y,b,c;};
_info info[ME];
struct _vertex{int in,out;};
_vertex v[MN];
#define OP(x) x+2
int main(int argc, char *argv[])
{
    setIO("sample");
    int ans1,ans2;
    int n = gi,m=gi;
    if(n == 0){
      puts("Impossible");
      return 0;
    }
    int ss=1,s = OP(1),t = OP(n),tt =2 ,sum = 0;
    for(int i = 1;i<=m;++i){
     info[i].x = gi,info[i].y = gi,info[i].b = gi,info[i].c = gi;
     if(info[i].c)
     {
      sum+=info[i].b;
      v[info[i].x].out += info[i].b;
      v[info[i].y].in += info[i].b;
      add(OP(info[i].x),OP(info[i].y),0);
     }
     else
      add(OP(info[i].x),OP(info[i].y),info[i].b);
    }
    for(int i = 1;i<=n;++i){
     add(ss,OP(i),v[i].in);
     add(OP(i),tt,v[i].out);
    }
    add(t,s,INF);node = OP(n);
    isap(ss,tt);
    if(ans != sum){
     puts("Impossible");
     return 0;
    }
    ans1 = lk[st[s]^1].f;
    lk[st[s]].f = lk[st[s]].c = 0;
    lk[st[s]^1].f = lk[st[s]^1].c = 0;
    ans2 = 0;
    isap(t,s);ans2 = ans;
    ans = ans1-ans2;
    if(ans < 0){
    lk[st[s]].f = lk[st[s]].c = 0;
    lk[st[s]^1].f = lk[st[s]^1].c = 0;
    ad(tt,s,-ans);
    isap(tt,t);
    ans = 0;
    }
    printf("%d\n",ans);
    for(int i = 1;i<=m;++i)
      printf(i==1?"%d":" %d",lk[i*2].f+info[i].b*info[i].c);
    puts("");
    closeIO();
    return EXIT_SUCCESS;
}