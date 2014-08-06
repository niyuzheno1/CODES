#include "mode.h"
#define MM 2000*2000*2
#define MN 2000*2
#undef TRA
#undef INF
#define INF 0x7f7f7f7f
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x=pre[lk[x^1].v])
#define GAP(x) if(--num[d[x]]==0) break;
#define BAL(x) lk[x].c-lk[x].f
struct edge{int n,v,f,c;};
edge lk[MM];
int st[MN],d[MN],pre[MN],cur[MN],node,num[MN],q[MN],ans,e = 1;
void init() {e = 1;CLEAR(st,0);}
void add(int x,int y,int z)
{
     ++e;lk[e].n =st[x],st[x] = e,lk[e].v = y,lk[e].f = 0,lk[e].c = z;
}
void bfs(int t)
{
     CLEAR(d,0x7f);
     int r = 0;
     d[t] = 0;q[r = 1] = t;++num[d[t]];
     for(int i = 1;i<=r;++i){
      int u = q[i];
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
    int ret = t,mf = INF;
    PRE(x,t)
    if(BAL(x)<=mf)
      ret = lk[x^1].v,mf = BAL(x);
    ans+=mf;
    PRE(x,t) lk[x].f += mf,lk[x^1].f -= mf;
    return ret;
}
void isap(int s,int t){
 bfs(t);
 for(int i = 1;i<=node;++i) cur[i]=st[i];
 int u = s;
 while(d[s]< node)
 {
   if(u == t) u = aug(t);
   int adv = 0;
   FIND(x,u)
    if(BAL(x) > 0 && d[lk[x].v]+1 == d[u])
    {
     adv = 1,cur[u]=x,u = lk[x].v,pre[u] = x;
     break;
    }
   if(!adv){
    GAP(u);
    int md = node;
    TRA(x,u)
     if(BAL(x)>0)
      md = min(md,d[lk[x].v]);
    d[u] = md+1;++num[d[u]];
    cur[u] = st[u];
    if(u != s) u = lk[pre[u]^1].v;
   }
 }
}
#define LEF(t) t+1
#define RIG(t) x+1+t
int run(int x){
 init();
 int s = 1,t = RIG(x)+1;
 for(int i = 1;i<=x;++i)
  for(int j = x;j>=i+1;--j)
  {
   int c = i+j;
   if(c == sqr(int(sqrt(c))))
    add(LEF(i),RIG(j),INF),add(RIG(j),LEF(i),0);
  }
 for(int i = 1;i<=x;++i)
  add(1,LEF(i),1),add(LEF(i),1,0);
 for(int i = 1;i<=x;++i)
  add(RIG(i),t,1),add(t,RIG(i),0);
 node = t;
 ans = 0;
 isap(s,t);
 return ans;
}
int p = 0;
int main(int argc, char *argv[])
{
    setIO("sample");
    p = gi;
    int l = 1,r = 1999;
    while(l<r)
    {
     int mid = (l+r)/2;
     int res = run(mid);
     int nex = run(mid+1);
     if(mid - res > p)
      r = mid-1;
     else if(mid - res == p && mid+1-nex==p)
      l = mid+1;
     else if(mid - res == p && mid+1-nex>p)
      l = mid,r = mid;
     else
      l = mid+1;
    }
    printf("%d",l);
    closeIO();
    return EXIT_SUCCESS;
}
