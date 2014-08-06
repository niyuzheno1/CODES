#include "mode.h"
#undef INF
#undef TRA
#define INF 0x7f7f7f7f
#define MN 1010
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x=pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]])==0) break;
#define BAL(x) lk[x].c-lk[x].f
#define INC(x) ++num[d[x]];
int n;
struct edge{int n,v,f,c;}lk[MN*MN*2];
int ans,a[MN],f[MN],st[MN],e=1,num[MN],pre[MN],d[MN],cur[MN],q[MN],node;
void init(){CLEAR(st,0);e =1;}
void add(int x,int y,int z)
{
     if(y == 2*n+1)
      y = 2*n+1;
     ++e,lk[e].f = 0,lk[e].n = st[x],st[x] = e,lk[e].c = z,lk[e].v=y;
}

void bfs(int t)
{
     int r = 0;
     CLEAR(d,0x7f);d[t]=0;INC(t);q[++r] = t;
     for(int i = 1;i<=r;++i)
     {
      int u = q[i];
      TRA(x,u)
       if(d[lk[x].v] >= INF)
       {d[lk[x].v] = d[u]+1,INC(lk[x].v);q[++r] = lk[x].v;}
     }
}
void clr(){
     for(int i = 2;i<=e;++i)lk[i].f = 0;
     CLEAR(num,0);CLEAR(cur,0);CLEAR(q,0);CLEAR(pre,0);
}
int aug(int t){
 int ret = t,mf = INF;
 PRE(x,t)
 if(BAL(x)<=mf)
  ret = lk[x^1].v,mf=BAL(x);
 ans += mf;
 PRE(x,t)
  lk[x].f+=mf,lk[x^1].f-=mf;
 return ret;
}
void isap(int s,int t){
 bfs(t);
 int u = s;
 for(int i = 1;i<=node;++i) cur[i]=st[i];
 while(d[s] < node){
  if(u == t) u = aug(t);
  int adv = 0;
  FIND(x,u)
  if(BAL(x)>0 && d[lk[x].v]+1==d[u])
  {
   adv = 1,cur[u]=x,u = lk[x].v,pre[u] = x;
   break;
  }
  if(!adv){
   GAP(u);
   int md = node;
   TRA(x,u)
    if(BAL(x)>0)
     md =min(md,d[lk[x].v]);
   cur[u] = st[u],d[u]=md+1,INC(u);
   if(u != s) u = lk[pre[u]^1].v;
  }
 }
}
#define A(x) 2*x
#define B(x) 2*x+1
int main(int argc, char *argv[])
{
    setIO("sample");
     n = gi;
    int s = 1,t = B(n)+1;
    node = t;
    for(int i = 1;i<=n;++i) a[i] = gi;
    int len = 1;
    for(int i = 1;i<=n;++i){
     f[i] = 1;
     for(int j = 1;j<=i-1;++j)
      if(a[j] < a[i] && f[j]+1>f[i])
       f[i] = f[j]+1,len=max(len,f[i]);
    }
    printf("%d\n",len);
    for(int i = 1;i<=n;++i)
     add(A(i),B(i),1),add(B(i),A(i),0);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=i-1;++j)
     if(a[j] < a[i] && f[j]+1==f[i])
     {
      add(B(i),A(j),1);add(A(j),B(i),0);
     }
    for(int i = 1;i<=n;++i){
     if(f[i] == 1){
      add(B(i),t,1);
      add(t,B(i),0);
     }
     if(f[i] == len) 
      add(s,A(i),1),add(A(i),s,0);
    }
    isap(s,t);
    printf("%d\n",ans);
    clr();
    TRA(x,A(1))
     if(lk[x].v == B(1))
      lk[x].c = INF;
    TRA(x,A(n))
     if(lk[x].v == B(n))
      lk[x].c = INF;
    TRA(x,B(1))
     if(lk[x].v == t)
      lk[x].c = INF;
    TRA(x,A(n))
     if(lk[x].v == s)
      lk[x^1].c = INF;
    ans = 0;
    isap(s,t);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
