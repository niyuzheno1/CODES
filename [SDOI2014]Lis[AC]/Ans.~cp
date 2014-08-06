#include "mode.h"
#include "netflow.h"
#define MN 710*2
#define MM 500010
typedef _nedge edge;
int n,st[MN],ans,pre[MN],num[MN],d[MN],q[MN],cur[MN],node,e=1,f[MN];
edge lk[MM];
void ad(int x,int y,int z){++e,lk[e].v = y,lk[e].n = st[x],st[x] = e,lk[e].c = z,lk[e].f=0;}
void add(int x,int y,int z){ad(x,y,z),ad(y,x,0);}
void bfs(int t)
{
 CLEAR(d,0x7f);CLEAR(num,0);
 int r=0;q[++r] = t,d[t] = 0,INC(t);
 for(int i = 1;i<=r;++i){
  int u = q[i];
  TRA(x,u)
   if(d[lk[x].v] >= INF && BAL(x^1)>0){
     d[lk[x].v] = d[u]+1;
     INC(lk[x].v);
     q[++r] = lk[x].v;
   }
 }
}
int aug(int t)
{
 int ret = t,mf =  INF;
 PRE(u,t) 
  if(BAL(u) <= mf)
   ret = lk[u^1].v,mf = BAL(u);
 ans += mf;
 PRE(u,t)
   lk[u].f += mf,lk[u^1].f -= mf;
 return ret;
}
void isap(int s,int t)
{
     ans = 0;
     CLEAR(pre,0);
     for(int i = 1;i<=node;++i) cur[i]=st[i];
     bfs(t);
     int u = s;
     while(d[s]<node)
     {
      if(u == t) u = aug(t);
      int adv = 0;
      FIND(x,u)
       if(BAL(x)>0&&d[lk[x].v]+1==d[u]){adv = 1,u = lk[x].v,pre[u] = x;break;}
       if(!adv)
       {
       GAP(u);int md = node;
       TRA(x,u) if(BAL(x)>0) md = min(md,d[lk[x].v]);
       cur[u] =st[u],d[u]=md+1,INC(u);
       if(u != s) u = lk[pre[u]^1].v;
       }
     }
}
struct note
{
 int a,b,c,d;
 bool operator < (note u) const
 {
      return c < u.c;
 }
};
note a[MN];
int ans2[MN];
#define LEF(x) x+1
#define RIG(x) x+n+1
int main(int argc, char *argv[])
{
    setIO("sample");
    int T;
    scanf("%d",&T);
    while(T--){
    CLEAR(st,0);
    e = 1;
    scanf("%d",&n);
    int s = 1,t = RIG(n)+1;
    node = t;
    for(int i = 1;i<=n;a[i].d = i,++i) scanf("%d",&a[i].a);
    for(int i = 1;i<=n;++i) scanf("%d",&a[i].b);
    for(int i = 1;i<=n;++i) scanf("%d",&a[i].c);
    int maxf = 0;
    for(int i = 1;i<=n;++i)
    {
     f[i] = 1;
     for(int j = 1;j<i;++j)
      if(a[i].a > a[j].a && f[i] < f[j]+1)
       f[i]=f[j]+1;
     maxf = max(maxf,f[i]);
    }
    for(int i = 1;i<=n;++i)
    {
     add(LEF(i),RIG(i),a[i].b);
     if(f[i] == 1) add(s,LEF(i),INF);
     if(f[i] == maxf) add(RIG(i),t,INF);
     for(int j  =1;j<i;++j)
      if(a[i].a > a[j].a && f[i] == f[j]+1)
       add(RIG(j),LEF(i),INF);
    }
    isap(s,t);
    sort(a+1,a+1+n);
    printf("%d",ans);
     SIZE(ans2) = 0;
    for(int x = 1;x<=n;++x)
    {
     int i = a[x].d;
     int ne = 0;
     TRA(x,LEF(i))
      if(lk[x].v == RIG(i)) 
      {
       ne = x;
       break;
      }
     if(BAL(ne) == 0)
     {
      bfs(RIG(i));
      if(d[LEF(i)] >= INF)
      {
       ans = 0;
       isap(LEF(i),s);
       isap(t,RIG(i));
       ++SIZE(ans2);
       ans2[SIZE(ans2)] = i;
       lk[ne^1].c = 0;
      }
     }
    }
    sort(ans2+1,ans2+1+SIZE(ans2));
    printf(" %d\n",SIZE(ans2));
    for(int i = 1;i<=SIZE(ans2);printf(i==SIZE(ans2)?"\n":" "),++i)
     printf("%d",ans2[i]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
