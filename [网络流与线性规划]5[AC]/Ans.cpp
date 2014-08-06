#include "mode.h"
#undef TRA
#undef INF
#define INF 0x7f7f7f7f
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x=pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]])==0)break;
#define BAL(x) lk[x].c-lk[x].f
#define MM 1010*100
#define MN 1010
struct edge{int n,f,v,c;};
edge lk[MM];
int st[MN],num[MN],d[MN],cur[MN],q[MN],pre[MN],node,ans,e=1,n,m;
vector<int> ansv[MN];
void add(int x,int y,int z){++e,lk[e].v = y,lk[e].n = st[x],st[x] = e,lk[e].c = z,lk[e].f = 0;}
void init(){e = 1,CLEAR(st,0);}
void bfs(int t){
 CLEAR(d,0x7f);
 int r=0;
 d[t] = 0;++num[d[t]];q[++r] = t;
 for(int i = 1,u;i<=r;++i){
  u = q[i];
  TRA(x,u)
   if(d[lk[x].v] >= INF)
     d[lk[x].v] = d[u]+1,++num[d[lk[x].v]],q[++r] = lk[x].v;
 }
}
int aug(int t)
{
    int ret = t,mf = INF;
    PRE(x,t)
     if(BAL(x) <= mf)
      mf = BAL(x) , ret = lk[x^1].v;
    ans += mf;
    PRE(x,t)
     lk[x].f += mf,lk[x^1].f-=mf;
    return ret;
}

void isap(int s,int t){
 bfs(t);
 for(int i = 1;i<=node;++i) cur[i] = st[i];
 int u = s;
 while(d[s] < node){
  if(u == t) u = aug(t);
  int adv = 0;
  FIND(x,u)
   if(BAL(x)>0 && d[lk[x].v]+1==d[u]){
    cur[u]=x,u = lk[x].v,pre[u] = x,adv = 1;
    break;
   }
  if(!adv){
   GAP(u);
   int md = node;
   TRA(x,u)
    if(BAL(x)>0)
     md = min(md,d[lk[x].v]);
   d[u] = md+1;
   cur[u] = st[u];
   ++num[d[u]];
   if(u != s) u = lk[pre[u]^1].v;
  }
 }
}
#define LEF(t) t+1
#define RIG(t) t+n+1
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    init();
    int s = 1,t=RIG(m)+1;
    node = t;
    int sum = 0;
    for(int i = 1;i<=n;++i)
    {
     int x = gi;add(s,LEF(i),x),add(LEF(i),s,0);
     sum+=x;
    }
    for(int i = 1;i<=m;++i){
     int x = gi;add(RIG(i),t,x);add(t,RIG(i),0);
    }
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      add(LEF(i),RIG(j),1),add(RIG(j),LEF(i),0);
    isap(s,t);
    if(ans < sum)
     puts("0");
    else
     puts("1");
    if(ans >= sum){
    for(int i = 1;i<=n;puts(""),++i)
     TRA(j,LEF(i))
      if(BAL(j)==0 && lk[j].v != s && lk[j].v != t)
       printf("%d ",lk[j].v-n-1);
     }
    closeIO();
    return EXIT_SUCCESS;
}
