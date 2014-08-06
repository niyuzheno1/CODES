#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define ff fprintf
using namespace std;
const int maxn = 400100,inf = 0x7f7f7f7f;
bool bl[maxn];
struct lnk
{
 int v,n,si;
};
lnk lk[maxn*2];
struct t
{
 int l;
 int s;
 int m;
 bool del;
};
struct li
{
 int a,b,c;
 bool operator<(li x)const
 {
  return b<x.b;
 }
};
li ne[maxn];
FILE * d;
t st[maxn];
int tot,ans,dfn[maxn],ti;
int last[maxn],now[maxn];
int k;
void add1(int x,int y,int z)
{tot++;lk[tot].v = y;lk[tot].si = z;lk[tot].n = st[x].s;st[x].s = tot;}
void add(int x,int y,int z)
{add1(x,y,z);add1(y,x,z);}
void dfs(int x,int y)
{
 if(st[x].del == 1)
 {
  st[x].l = 0;
  st[x].m = 0;
  return;
 }
 ti++;
 dfn[ti] = x;
 st[x].l = 1,st[x].m=0;
 for(int i = st[x].s;i != 0;i = lk[i].n)
 {
  int u = lk[i].v;
  if(u != y)
  {
   dfs(u,x);
   st[x].l += st[u].l;
   st[x].m = max(st[u].l,st[x].m);
  }
 }
}
int getG(int x,int y)
{
 int maxv = 0,maxt = inf;
 for(int i = 1;i<=ti;i++)
 {
  int x = dfn[i];
  st[x].m = max(st[x].m,y-st[x].l);
  if(maxt>st[x].m)
  {
  maxv = x;
  maxt=st[x].m;
  }
 }
 return maxv;
}
void dpr(int l,int r)
{
 for(int i = l;i<=r;i++)
  ff(d,"%d:%d %d\n",i,st[i].l,st[i].m);
}
void dpr2(int l,int r)
{
 for(int i = l;i<=r;i++)
  ff(d,"%d: %d %d %d \n",i,ne[i].a,ne[i].b,ne[i].c);
}
void dfs2(int x,int y,int m,int z)
{
 if(z > k)
  return;
 if(st[x].del == 1)
  return;
 ne[m].b = max(ne[m].b,z);
 for(int i = st[x].s;i!= 0;i=lk[i].n)
 {
  int u = lk[i].v;
  if(u != y)
   dfs2(u,x,m,z+bl[u]);
 }
}
void dfs3(int x,int y,int m,int z)
{
 if(m > k)
  return;
 if(st[x].del == 1)
  return;
 now[m] = max(z,now[m]);
 for(int i = st[x].s;i!= 0;i=lk[i].n)
 {
  int u = lk[i].v;
  if(u != y)
   dfs3(u,x,m+bl[u],z+lk[i].si);
 }
}
void co(int x)
{
 st[x].del = 1;
 for(int i = st[x].s;i != 0;i = lk[i].n)
 {
   int u =  lk[i].v;
   ti++;
   ne[ti].a = u;ne[ti].b = 0;ne[ti].c = lk[i].si;
   dfs2(u,x,ti,bl[u]);
 }
 sort(ne+1,ne+1+ti);
 //dpr2(1,ti);
 for(int i = 1;i<=ti;i++)
 {
   dfs3(ne[i].a,x,bl[ne[i].a],ne[i].c);
   for(int j = 0;j<=ne[i].b;j++){
     int r = min(k-j-bl[x],ne[i-1].b);
     if(last[r] == -inf)break;
     if(now[j] != -inf)
     ans = max(ans,now[j]+last[r]);
    }
   for(int j = 0;j<=ne[i].b;j++){
    last[j] = max(last[j],now[j]),now[j]=-inf;
    if(j) last[j] = max(last[j-1],last[j]); 
   }
 }
 for(int j = 0;j<=ne[ti].b;j++)
  last[j] = -inf;
 
 //ff(d,"%d\n",ans);
}
void sol(int x,int y)
{
 ti = 0;
 dfs(x,-1);
 x = getG(x,y);
 ti = 0;
 co(x);
 for(int i = st[x].s;i != 0;i = lk[i].n)
 {
  int u = lk[i].v;
  if(!st[u].del)
   sol(u,st[u].l);
 }
}
int n,m;
int main(int argc, char *argv[])
{
    //freopen("spoj1825.in","r",stdin);
    //freopen("spoj1825.out","w",stdout);
    //d = fopen("debug.txt","w");
    scanf("%d%d%d",&n,&k,&m);
    for(int i = 0;i<=k;i++)
     last[i] = now[i] = -inf;
    for(int i = 1;i<=m;i++)
    {int x;scanf("%d",&x);bl[x] = 1;}
    for(int i = 1;i<=n-1;i++)
    {int x,y,z;scanf("%d%d%d",&x,&y,&z);add(x,y,z);}
    //dpr(1,n);
    ans = -inf;
    sol(1,n);
    printf("%d\n",ans);
    //fclose(d);
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
